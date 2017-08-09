#include "raiz_fx.h"

//#define _I_MAX 1000000
//#define DEBUG

double raizBisseccao(std::string f, double a, double b, double e, int &i, int max){
	f = clean_fx(f);
	if(a>b) std::swap(a,b);
	double x, f_x, f_a, f_b, er;
	i=0;
	f_a=fx(a, f);
	f_b=fx(b, f);
	
	do{
		i++;
		x=(a+b)/2;
		f_x=fx(x, f);
		if(f_x==0)return x;
		if((f_a>0&&f_x<0) || (f_a<0&&f_x>0)){
			b=x;
			f_b=f_x;
		}else{
			a=x;
			f_a=f_x;
		}
		er=(b-a);	//b é maior que a
	}while(er>e && i<max);
	return x;
}

double raizPontoFalso(std::string f, double a, double b, double e, int &i, int max){
	f = clean_fx(f);
	if(a>b) std::swap(a,b);
	double x, f_x, f_a, f_b, er;
	i=0;
	f_a=fx(a, f);
	f_b=fx(b, f);
	
	do{
		i++;
		x=(a*f_b-b*f_a)/(f_b-f_a);
		f_x=fx(x, f);
		if(f_x==0)return x;
		if((f_a>0&&f_x<0) || (f_a<0&&f_x>0)){
			b=x;
			f_b=f_x;
		}else{
			a=x;
			f_a=f_x;
		}
		er=(b-a);	//b é maior que a
		//cout<<"|x["<<i<<"]| = "<<x<<" - |er["<<i<<"]| = "<<er<<endl;
	}while(er>e && i<max);
	return x;
}

double raizNewton(std::string f, double x0, double e, int &i, int max){
	f = clean_fx(f);
	std::string df = dfx(f);
	
	#ifdef DEBUG
		std::cout<<f<<std::endl;	//debug
		std::cout<<df<<std::endl;	//debug
	#endif
	
	double x, er;
	i=0;
	do{
		//x=x0-(f(x0)/df(x0));
		x=x0-(fx(x0, f)/fx(x0, df));
		er=(x-x0)/x;		//calcula o erro
		if(er<0)er=-er;		//pega o modulo do erro
		x0=x;				//troca o alor do X0 para o proximo ciclo
		i++;
		//cout<<"|er["<<i<<"]| = "<<er<<endl;
	}while(er>e && i<max);	//teste de parada
	return x;					//retorno da raiz
}

double raizSecante(std::string f, double x0, double x1, double e, int &i, int max){
	f = clean_fx(f);
	double x, f_x, f_x0, f_x1, er;
	i=0;
	f_x0 = fx(x0, f);
	f_x1 = fx(x1, f);
	do{
		x=(x0*f_x1-x1*f_x0)/(f_x1-f_x0);
		f_x=fx(x, f);
		if(f_x==0)return x;
		
		er=(x-x1)/x;		//calcula o erro
		if(er<0)er=-er;		//pega o modulo do erro
		
		x0=x1;
		x1=x;
		f_x0=f_x1;
		f_x1=f_x;
		i++;
		//cout<<i<<" x="<<x<<" fx="<<fx<<" - er="<<er<<endl;
	}while(er>e && i<max);	//teste de parada
	return x;					//retorno da raiz
}
