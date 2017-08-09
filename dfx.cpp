#include "dfx.h"

#ifndef DEBUG
	//#define DEBUG		//uncoment to display function comentaries
#endif

std::string dfx(std::string f){
	#ifdef DEBUG
		std::cout<<"f(x): "<<f<<std::endl;	//debug
	#endif
	
	if(f=="x") return "1";
	if(f=="#x") return "#1";
	
	int np=0;
	
	//derivada da soma (propriedade: a derivada das somas é a soma das deriadas)
	//ex: (2*x)^2+x
	//separa em '(2*x)^2' e 'x'
	for(int i=0; i<f.size(); i++){
		if(f[i]=='('){
			np++;
		}else if(f[i]==')'){
			np--;
			if(np<0) throw -1;	//throw SintaxeException("Impossible to solve "+func);
		}else if(np==0 && f[i]=='+'){
			std::string a=dfx(f.substr(0,i)), b=dfx(f.substr(i+1,f.size()-i-1));
			if(a=="0"){
				if(b=="0"){
					return "0";
				}
				return b;
			}if(b=="0"){
				return a;
			}
			return a+"+"+b;
		}
	}
	//fim da derivada da soma
	
	#ifdef DEBUG
		std::cout<<"parte 1"<<std::endl;	//debug
	#endif
	
	//separa em produtos
	for(int i=0; i<f.size(); i++){
		if(f[i]=='('){
			np++;
		}else if(f[i]==')'){
			np--;
			if(np<0) throw -1;	//throw SintaxeException("Impossible to solve "+func);
		}else if(np==0 && f[i]=='*'){
			std::string a = f.substr(0, i), b = f.substr(i+1, f.size()-i-1);
			double ad, bd;
			try{					//usa try-catch para ver ser é uma constante
				ad = toDouble(a);
				try{
					bd = toDouble(b);
					return "0";			//(k1*k2)' = (k)' = 0
				}catch (std::exception& e){
					b=dfx(b);
					if(b=="0") return "0";
					if(b=="1") return a;
					return a+"*"+b;	//(k*g_x)' = k*(g_x)'
				}
			}catch (std::exception& e){
				try{
					bd = toDouble(b);
					a=dfx(a);
					if(a=="0") return "0";
					if(a=="1") return b;
					return b+"*"+a;		//(g_x*k)' = k*(g_x)'
				}catch (std::exception& e){
					std::string d_a=dfx(a), d_b=dfx(b);
					//(g_x*h_x)' = g_x*(h_x)'+(g_x)'*h_x
					return a+(d_b=="1"? "" :"*"+d_b) +"+"+ (d_a=="1"? "" :d_a+"*")+b;
				}
			}
		}
	}
	
	#ifdef DEBUG
		std::cout<<"parte 2"<<std::endl;	//debug
	#endif
	
	//separa em potencias
	for(int i=0; i<f.size(); i++){
		if(f[i]=='(') np++;
		else if(f[i]==')'){
			np--;
			if(np<0) throw -1;	//throw SintaxeException("Impossible to solve "+func);
		}else if(np==0 && f[i]=='^'){
			std::string a = f.substr(0,i), b = f.substr(i+1,f.size()-i-1);
			double ad, bd;
			try{					//usa try-catch para ver ser é uma constante
				ad = toDouble(a);
				try{
					bd = toDouble(b);
					return "0";			//(k1^k2)' = (k)' = 0
				}catch (std::exception& e){
					throw -1;	//throw SintaxeException("Impossible to solve "+func);
					//return ad*dfx(b);	//(k^g_x)' = ?	tem que ver
				}
			}catch (std::exception& e){
				try{
					bd = toDouble(b)-1;	//std::to_string(bd) == b
					std::string d_a = dfx(a);
							//(g_x^k)' = k*(g_x)^(k-1)*(g_x)'
					return (b!="1"? b+"*" : "")+a+(bd==1? "" : "^"+std::to_string(bd))+(d_a=="1"?"":"*"+dfx(a));
				}catch (std::exception& e){
					throw -1;	//throw SintaxeException("Impossible to solve "+func);
					//return b*dfx(a)+a*dfx(b);	//(g_x^h_x)' = ?
				}
			}
		}
	}
	
	#ifdef DEBUG
		std::cout<<"parte 3"<<std::endl;	//debug
	#endif
	
	//busca funções basicas tipo sin, cos, ln...
	if( (f[0]=='#' && f[1]!='e' && f[1]!='x' && std::isalpha(f[1])) || (f[0]!='e'&&f[0]!='x'&&std::isalpha(f[0])) ){
		
		#ifdef DEBUG
			std::cout<<"parte 4, entrou"<<std::endl;	//debug
		#endif
		
		//012345
		//sin(x)
		for(int i=0; i<f.size()-4; i++){
			if(f[i]=='s')
				if(f[i+1]=='i')
					if(f[i+2]=='n')
						if(f[i+3]=='('){
							int n=0;
							for(int j=i+4; j<f.size(); j++){
								if(f[j]==')'){
									if(n==0){
										std::string s=f.substr(i+4, j-i-4), ds=dfx(s), res="";
										if(ds=="0") return "0";
										//if(i>0 && f[i-1]=='#' && ds[0]!='#') res="#";
										if(i>0 && f[i-1]=='#') res="#";
										if(ds!="1") res+=ds+"*";
										res+="cos("+s+")";
										return res;
									}
									else n--;
								}
								else if(f[j]=='(') n++;
							}
							throw -1;	//throw SintaxeException("Impossible to solve "+func);
						}
			if(f[i]=='c')
				if(f[i+1]=='o')
					if(f[i+2]=='s')
						if(f[i+3]=='('){
							int n=0;
							for(int j=i+4; j<f.size(); j++){
								if(f[j]==')'){
									if(n==0){
										std::string s=f.substr(i+4, j-i-4), ds=dfx(s), res;
										if(ds=="0") return "0";
										//if(i>0 && f[i-1]!='#' && ds[0]!='#') res="#";
										if(i==0) res="#";
										if(ds!="1") res+=ds+"*";
										res+="sin("+s+")";
										return res;
										
										//std::string s=f.substr(i, j-i), ds=dfx(s);
										//if(ds=="0") return "0";
										//if(i>0 && f[i-1]=='#')
										//	return "sin"+s+"*"+ds;
										//return "#sin"+s+"*"+ds;
									}
									else n--;
								}
								else if(f[j]=='(') n++;
							}
							throw -1;	//throw SintaxeException("Impossible to solve "+func);
						}
			if(f[i]=='e')	//e^x
				if(f[i+1]=='x')
					if(f[i+2]=='p')
						if(f[i+3]=='('){
							int n=0;
							for(int j=i+4; j<f.size(); j++){
								if(f[j]==')'){
									if(n==0){
										std::string s=f.substr(i, j-i), ds=dfx(s);
										if(ds=="0") return "0";
										if(i>0 && f[i-1]=='#')
											return "#exp"+s+"*"+ds;
										return "exp"+s+"*"+ds;
										//return ""+(i>0 && f[i-1]=='#'?"#e":"e")+"xp"+s+"*"+ds;
									}
									else n--;
								}
								else if(f[j]=='(') n++;
							}
							throw -1;	//throw SintaxeException("Impossible to solve "+func);
						}
			if(f[i]=='l')
				if(f[i+1]=='o')
					if(f[i+2]=='g')
						if(f[i+3]=='(')
							throw 1;	//throw SintaxeException("Not implemented");
			if(f[i]=='l')
				if(f[i+1]=='n')
						if(f[i+3]=='(')
							throw 1;	//throw SintaxeException("Not implemented");
						
		}
	}
	
	#ifdef DEBUG
		std::cout<<"parte 6, saiu"<<std::endl;	//debug
	#endif
	
	//é uma constante, a derivada é 0
	return "0";
}
