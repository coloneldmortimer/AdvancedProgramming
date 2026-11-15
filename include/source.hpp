#ifndef SOURCE_HPP
#define SOURCE_HPP

class Source{
private:
    double energy;
    double energy_alt;
    double x_min;
    double x_max;
    double y_min;
    double y_max;

public:

    Source(double energy, double energy_alt = 600, double x_min = 0.00, double x_max = 1.60, double y_min = 0.00, double y_max = 1.00)
    : energy(energy), energy_alt(energy_alt), x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max){}
    
    double getEnergy(double x, double y);
};

#endif