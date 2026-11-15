#ifndef JACOBI_SOLVER_HPP
#define JACOBI_SOLVER_HPP
#include "physical_grid.hpp"

class JacobiSolver{
private:
    unsigned int maxIterations;
    double tolerance;

public:
    JacobiSolver(unsigned int maxIterations, double tolerance);

    void solve(Grid& grid);
};

#endif