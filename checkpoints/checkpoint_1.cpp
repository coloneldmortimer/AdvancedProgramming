#include <iostream>
#include "../include/physical_constrains.hpp"
#include "../src/physical_grid.cpp"

int main() {
	std::cout << "CHECKPOINT 1 - Standard-library baseline" << std::endl;

    std::cout << "\n1. Creation and initialization of a 3x3 grid." << std::endl;
	Grid physical_grid(3, 3);
	physical_grid.printMatrix();

    std::cout << "\n2. Calculation of the central point temperature." << std::endl;
    physical_grid.computeSMTemperature(unif);
	physical_grid.printMatrix();

	return 0;
}