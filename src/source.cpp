#include <stdexcept>
#include "../include/source.hpp"

Source::Source(double energy, double energy_alt, double x_min, double x_max, double y_min, double y_max)
: energy(energy), energy_alt(energy_alt), x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max){
    if(!(x_min >= 0.0 && x_max <= 1.60 && y_min >= 0.0 && y_max <= 1.00)){
        throw std::invalid_argument("Error: Boundaries must be smaller than the dimension of the panel!");
    }
}


double Source::getEnergy (double x, double y) {
    if ((x >= x_min && x <= x_max) || (y >= y_min && y <= y_max)) {
        return energy;
    } else{
        return energy_alt;
    }
}