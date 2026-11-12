#include <iostream>
#include "../src/physical_grid.cpp"

int main() {
	std::cout << "TEST OF THE TEMPERATURE INFORMATION METHODS OF THE CLASS 'Grid' WITH A 3x3 PHYSICAL GRID\n" << std::endl;
	Grid physical_grid(3, 3);

	std::cout << "TEST 1 - Mean temperature of initialized grid [correct: 265.02]: " << physical_grid.getMeanTemperature() << std::endl;
	std::cout << "TEST 2 - Maximum temperature of initialized grid [correct: 298.15]: " << physical_grid.getMaxTemperature().value << std::endl;
	std::cout << "TEST 3 - Delta temperature of initialized grid [correct: 0]: " << physical_grid.getDeltaTemperature() << std::endl;


	return 0;
}