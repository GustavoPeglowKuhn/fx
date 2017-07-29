#ifndef _FX_H
#define _FX_H

#include <iostream>
#include <cmath>
#include <exception>

std::string clean_fx(std::string f);	//executar essa funcao antes para "limpar" a string

double toDouble(std::string s);
double fatorial(double d);
double f_x(double x, std::string f);

#endif