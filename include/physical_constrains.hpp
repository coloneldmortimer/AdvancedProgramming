#ifndef PHYSICAL_CONSTRAINS_HPP
#define PHYSICAL_CONSTRAINS_HPP
#include "source.hpp"


// Measurements of the solar panel
const double L_X = 1.6;
const double L_Y = 1.0;


// Parameters of the governing equation
const double K = 0.45;
const int H = 10;
const double T_AMB = 298.15;

// Sources of heat (uniform or with a local hotspot)
Source unif(600);
Source hot(600, 1200, 0.60, 1.00, 0.35, 0.65);


#endif