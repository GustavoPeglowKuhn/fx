//#ifndef DEBUG
//#define DEBUG	//uncoment to display function comentaries
//#endif

#include "fx.h"

std::string clean_fx(std::string f){
	for(int i=0;i<f.size();i++){
		if(f[i]=='-'){
			if(i==0){
				f.replace(i,1,"#");
			}else{
				f.replace(i,1,"+#");
			}
			#ifdef DEBUG
				std::cout<<f<<std::endl;	//debug
			#endif
		}//else if(f[i] == ' ') f.erase(i, 1);
	}
	return f;
}

double toDouble(std::string s){
	return (s[0]=='#'? -std::stod(s.substr(1,s.size())):stod(s));
}

double fatorial(double d){
	//if(abs(d)!=d) throw new exception("fatorial aloed only for integers");
	double res=1;
	for(;d>1;d--) res*=d;	
	return res;
}

double f_x(double x, std::string f){
	if(f=="x") return x;
	if(f=="#x") return -x;
	int np=0,pos;
	for(int i=0;i<f.size();i++){
		if(f[i]=='('){
			if(np==0)pos=i;
			np++;
		}else if(f[i]==')'){
			np--;
			if(np==0){
				if(pos==i-1){
					f.erase(pos,2);
					#ifdef DEBUG
						std::cout<<f<<std::endl;	//debug
					#endif
				}else{
					double d;
					d = f_x(x,f.substr(pos+1,i-pos-1));
					f.replace(pos,i-pos+1,std::to_string(d));	//inicio, tamanho, outra string
					#ifdef DEBUG
						std::cout<<f<<std::endl;	//debug
					#endif
				}
			}else{
				if(np>0){
					#ifdef DEBUG
						std::cout << "missing a ')'"<<std::endl;
					#endif
					//throw a exeption
				}else{
					#ifdef DEBUG
						std::cout << "missing a '('"<<std::endl;
					#endif
					//throw other exeption
				}
			}
		}else if(f[i]!='e' && f[i]!='x' && std::isalpha(f[i])){
		//testar as funcoes tipo seno
		#ifdef DEBUG
			std::cout<<"isalpha"<<std::endl;
		#endif
		}
	}	
	for(int i=0;i<f.size();i++){
		if(f[i]=='+') return f_x(x,f.substr(0,i)) + f_x(x,f.substr(i+1,f.size()-i));
		//if(f[i]=='-' && i!=0) return f_x(x,f.substr(0,i)) - f_x(x,f.substr(i+1,f.size()-i ) );
	}
	for(int i=0;i<f.size();i++){
		if(f[i]=='*') return f_x(x,f.substr(0,i)) * f_x(x,f.substr(i+1,f.size()-i));
		if(f[i]=='/') return f_x(x,f.substr(0,i)) / f_x(x,f.substr(i+1,f.size()-i));
	}
	for(int i=0;i<f.size();i++){
		if(f[i]=='^') return pow(f_x(x,f.substr(0,i)), f_x(x,f.substr(i+1,f.size()-i)));
	}
	#ifdef DEBUG
		std::cout << "returnning stod of "<<f<<std::endl;
	#endif
	if(f[f.size()-1]=='!') return fatorial(toDouble(f.substr(0,f.size()-1)));
	//  return (f[0]=='#'?-stod(f.substr(1)):stod(f));
	return toDouble(f);
}
