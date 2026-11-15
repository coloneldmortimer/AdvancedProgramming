#include "jacobi.hpp"
#include "physical_constrains.hpp"
#include <cmath>
#include <stdexcept>
#include <utility>

JacobiResult jacobi(unsigned int nx, unsigned int ny, double tolerance, unsigned int maxIterations){

    if(nx < 3 || ny < 3 || tolerance <= 0 || !std::isfinite(tolerance) || maxIterations == 0){
        throw std::invalid_argument("Invalid Jacobi parameters");
    }

    if(K <= 0 || H <= 0 || L_X <= 0 || L_Y <= 0 ||
       !std::isfinite(K) || !std::isfinite(H) || !std::isfinite(L_X) ||
       !std::isfinite(L_Y) || !std::isfinite(T_AMB)){
        throw std::invalid_argument("Invalid physical parameters");
    }
    Grid oldGrid(nx, ny);
    Grid newGrid(nx, ny);
    Source uniform(600.0);

    for(unsigned int j=0; j<ny; j++){
        for(unsigned int i=0; i<nx; i++){
            oldGrid.setValue(i,j,T_AMB);
            newGrid.setValue(i,j,T_AMB);
        }
    }
    double dx = L_X / (nx-1);
    double dy = L_Y / (ny-1);
    double ax = K / (dx*dx);
    double ay = K / (dy*dy);
    double denominator = 2*(ax+ay) + H;
    unsigned int k = 0;
    double maxChange = 0;
    bool converged = false;
    
    while (k< maxIterations){
        maxChange = 0;
        for(unsigned int j=1; j<ny-1; j++){
            for(unsigned int i=1; i<nx-1; i++){
                double left = oldGrid.getValue(i-1, j);
                double right = oldGrid.getValue(i+1, j);
                double top = oldGrid.getValue(i, j+1);
                double bottom = oldGrid.getValue(i, j-1);
                double q = uniform.getEnergy(i*dx, j*dy);
                
                double newValue = (q + H*T_AMB +
                    ax*(left+right) + ay*(top+bottom)) / denominator;

                newGrid.setValue(i,j,newValue);

                double change = std::abs(newValue-oldGrid.getValue(i,j));

                if(change > maxChange){
                    maxChange = change;
                }
            }
        }

        k++;
        std::swap(oldGrid,newGrid);

        if(maxChange <= tolerance){
            converged = true;
            break;
        }
    }

    return {oldGrid, converged, k, maxChange};
}
