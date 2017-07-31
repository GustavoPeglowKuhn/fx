#ifndef _DFX_H
#define _DFX_H

#include <iostream>
#include <cmath>

using namespace std;

//ex: (2*x)^2+x
//separa em '(2*x)^2' e 'x'

std::string clean_fx(std::string f);
std::string unclean_fx(std::string f);

double toDouble(std::string s);

std::string d_f_x(std::string f);
#endif	//_DFX_H
