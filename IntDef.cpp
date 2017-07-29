#include <iostream>
#include <cmath>
#include "fx.h"

using namespace std;

int main(){
	string foo;
	double xi, xf, dx;
	bool inverso=false;
	cout <<endl<<"AVISO: ";
	cout <<endl<<"pelo metodo utilizado, este programa pode demorar muito para resoler a equacao";
	cout <<endl<<"teste com uma precisao menor primeiro"<<endl<<endl;
	
	cout <<endl<<"digite a f(x): ";cin>>foo;
	cout<<endl<<"digite o valor de xi : ";cin>>xi;
	cout<<endl<<"digite o valor de xf : ";cin>>xf;
	//if(xi>xf){swap(xi,xf); inverso=true;}
	if(xi>xf) inverso=true;
	cout<<endl<<"digite a precisao (entre 5 e 15): ";cin>>dx;
	if(dx<3 || dx > 15){
		cout<<"valor de precissão invalido";
		return 1;
	}
	dx = pow(10, -dx);
	cout<<endl<<"Please wait!\nif it take to long press 'ctrl+c'"<<endl<<endl<<endl;
	try{
		string fc = clean_fx(foo);
		double sum=0;
		for(double x=(inverso?xf:xi); x<(inverso?xi:xf); x+=dx)
			sum+=f_x(x,fc)*dx;
		if(inverso) sum = -sum;
		//cout<<"f(x) = "<<fc<<endl;
		cout<<"integral de "<<foo<<" de "<<xi<<" a "<<xf<<" = "<<sum<<endl;
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
