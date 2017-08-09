#include <iostream>
#include "fx.h"

using namespace std;

int main(){
	string foo;
	double x;
	cout <<endl<<"digite a f(x): ";cin>>foo;
	cout<<endl<<"digite o valor de x: ";cin>>x;
	cout<<endl<<"Please wait!\nif it take to long press 'ctrl+c'"<<endl<<endl<<endl;
	try{
		string fc = clean_fx(foo);		//'prepara' a string para facilitar o processamento
		double y=fx(x,fc);
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
