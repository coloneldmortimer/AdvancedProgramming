#include "../include/physical_grid.hpp"
#include "../include/jacobi_solver.hpp"

JacobiSolver::JacobiSolver(unsigned int maxIterations, double tolerance)
: maxIterations(maxIterations), tolerance(tolerance){
    //
}

void JacobiSolver::solve(Grid& grid){
    // 
};