#ifndef _RAIZ_FX_H
#define _RAIZ_FX_H

#include <iostream>
#include "fx.h"
#include "dfx.h"

double raizBisseccao(std::string f, double a, double b, double e, int &i, int max=1000000);
double raizPontoFalso(std::string f, double a, double b, double e, int &i, int max=1000000);
double raizSecante(std::string f, double x0, double x1, double e, int &i, int max=1000000);
double raizNewton(std::string f, double x0, double e, int &i, int max=1000000);

#endif	//_RAIZ_FX_H