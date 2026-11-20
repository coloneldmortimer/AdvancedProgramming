#include <iostream>
#include "../include/physical_constrains.hpp"
#include "../src/physical_grid.cpp"
#include "../src/jacobi.cpp"

int main() {
	std::cout << "CHECKPOINT 1 - Standard-library baseline" << std::endl;

    std::cout << "\n1. Creation and initialization of a 3x3 grid." << std::endl;
	Grid gridOne(3, 3);
	gridOne.printMatrix();

    std::cout << "\n2. Calculation of the central point temperature." << std::endl;
    gridOne.computeSMTemperature(unif);
	gridOne.printMatrix();

	std::cout << "\n3. Jacobi solution for a 9x7 grid and temperature informations" << std::endl;
	Grid gridTwo(9, 7);
	JacobiResult jacobiTwo(gridTwo);
	jacobiTwo.calculateSolution(1E-10, 1E6);

	return 0;
}