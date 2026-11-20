#ifndef JACOBI_HPP
#define JACOBI_HPP

#include "physical_grid.hpp"

struct JacobiResult {
private:
    Grid grid;
    bool converged;
    unsigned int iterations;
    double finalUpdate;

    // Print the informations of the jacobi solution
    void printJacobiInfo();

public:
    // Constructor
    JacobiResult(Grid& grid);

    // Calculate the solution of the system using the Jacobi method
    // tolerance: tolerance of the residual error
    // maxIterations: maximum number of iterations for the method
    void calculateSolution(double tolerance, unsigned int maxIterations);
};

#endif
