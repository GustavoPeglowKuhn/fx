#ifndef _FX_H
#define _FX_H

#include <iostream>
#include <cmath>
#include <exception>

std::string clean_fx(std::string f);	//executar essa funcao antes para "limpar" a string
std::string unclean_fx(std::string f);	//"desfaz" as mudancas da funcao acima

double toDouble(std::string s);
double fatorial(double d);

double fx(double x, std::string f);

#endif