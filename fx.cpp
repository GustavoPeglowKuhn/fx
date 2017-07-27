//#define DEBUG	//uncoment to display function comentaries

#include <iostream>
#include <cmath>
#include <exception>

using namespace std;
//using namespace  std::exception;

//
double toDouble(string s){
	return (s[0]=='#'? -stod(s.substr(1,s.size())):stod(s));
}

double fatorial(double d){
	//if(abs(d)!=d) throw new exception("fatorial aloed only for integers");
	double res=1;
	for(;d>1;d--){
		res*=d;
	}
	return res;
}

double f_x(double x, string f){
	if(f=="x") return x;
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
						cout<<f<<endl;	//debug
					#endif
				}else{
					double d;
					d = f_x(x,f.substr(pos+1,i-pos-1));
					f.replace(pos,i-pos+1,to_string(d));	//inicio, tamanho, outra string
					#ifdef DEBUG
						cout<<f<<endl;	//debug
					#endif
				}
			}else{
				if(np>0){
					cout << "missing a ')'"<<endl;
					//throw a exeption
				}else{
					cout << "missing a '('"<<endl;
					//throw other exeption
				}
			}
		}else if(f[i]!='e' && f[i]!='x' && isalpha(f[i])){
		//testar as funcoes tipo seno
		cout<<"isalpha"<<endl;
		}
	}
	for(int i=0;i<f.size();i++){
		if(f[i]=='-'){
			if(i==0){
				f.replace(i,1,"#");
			}else{
				f.replace(i,1,"+#");
			}
			#ifdef DEBUG
				cout<<f<<endl;	//debug
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
	cout << "returnning stod of "<<f<<endl;
	if(f[f.size()-1]=='!') return fatorial(toDouble(f.substr(0,f.size()-1)));
	//  return (f[0]=='#'?-stod(f.substr(1)):stod(f));
	return toDouble(f);
}

int main(){
	string foo;
	double x;
	cout <<endl<<"digite a f(x): ";cin>>foo;
	cout<<endl<<"digite o valor de x: ";cin>>x;
	cout<<endl<<"Please wait!\nif it take to long press 'ctrl+c'"<<endl<<endl<<endl;
	try{
		double y=f_x(x,foo);  
		cout<<"f(x) = "<<foo<<endl;
		cout<<"f("<<x<<") = "<<y<<endl;
	}catch (std::exception& e){
		std::cerr << "exception caught: " << e.what() << endl;
		cout<<"tente navamente verificando a sintaxe"<<endl;
	}
	/// apenas para travar a tela
	/// comente essas 2 caso á usa-lo direto pelo terminal
	/// pode comentar o #include<conio.h> também
	//cout<<endl<<"precione qualquer tecla para finalizar";
	//getch();

	return 0;
}
