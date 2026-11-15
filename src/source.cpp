#include "../include/source.hpp"

double Source::getEnergy (double x, double y) {
    if ((x >= x_min && x <= x_max) || (y >= y_min && y <= y_max)) {
        return energy;
    } else{
       return energy_alt;
    }
}