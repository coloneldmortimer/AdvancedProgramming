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

    // Constructor
    // energy: value of energy inside the boundaries
    // energy_alt: value of energy outside the boundaries
    //x_min, x_max, y_min, y_max: boundaries
    Source(double energy, double energy_alt = 600, double x_min = 0.00, double x_max = 1.60, double y_min = 0.00, double y_max = 1.00);

    // Return the energy for the point (x,y)
    double getEnergy(double x, double y);
};

#endif