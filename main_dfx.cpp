#include <iostream>
#include "dfx.h"

using namespace std;

int main(){
	string func;
	cout<<"func: "; cin>>func;
	cout<<endl;
	
	try{
		string d_func = dfx(func);
		cout<<"("<<func<<")' = "<<d_func<<endl;
	}catch(exception &e){
		cout<<"NOP"<<endl<<"not today"<<endl;
	}catch(int i){
		cout<<"erro "<<i<<endl;
		cout<<"Algo errado na sintaxe ou esta funcao ainda nao foi implementada"<<endl;
		cout<<"Verifique se este ssoftware esta atualizado"<<endl;
	}
	
	return 0;
}