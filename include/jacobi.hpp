#ifndef JACOBI_HPP
#define JACOBI_HPP

#include "physical_grid.hpp"

struct JacobiResult {
    Grid grid;
    bool converged;
    unsigned int iterations;
    double finalUpdate;
};

JacobiResult jacobi(unsigned int nx, unsigned int ny,
                    double tolerance, unsigned int maxIterations);

#endif
