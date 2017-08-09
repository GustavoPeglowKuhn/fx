#include <iostream>
#include "fx.h"
#include "dfx.h"
#include "raiz_fx.h"

using namespace std;

#define _I_MAX 1000000
//#define DEBUG

int main(){
	double x0, e;
	string func;
	int i;
	
	cout<<endl<<"digite a funcao: ";cin>>func;
	cout<<endl<<"digite o x0:     ";cin>>x0;
	cout<<endl<<"digite o erro:   ";cin>>e;
	e=pow(10, -e);
	
	try{
		cout << "Newton Raphson =  " << raizNewton(func, x0, e, i) <<endl;
		if(i==_I_MAX) cout<<"I=MAX"<<endl<<endl;
		else cout<<i<<'\t'<<" iteracoes"<<endl<<endl;
	}catch(exception &e){
		cout<<"erro inesperado:\t";
		cout<<e.what()<<endl;
		cout<<"Better call Saul!"<<endl;
	}catch(int erro){
		cout<<"o Alemao preguisozo ainda nao implementou esse metodo"<<endl;
		cout<<"diga para ele que ocorreu o erro "<<erro<<" com a funcao:"<<endl;
		cout<<func<<endl;
		cout<<"May the force be with you"<<endl;
	}
	
}