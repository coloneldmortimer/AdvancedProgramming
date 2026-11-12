#import <iostream>
#import "../src/physical_grid.cpp"

int main() {
	std::cout << "TEST OF THE BASIC METHODS OF THE CLASS 'Grid' WITH A 3x3 PHYSICAL GRID\n" << std::endl;
	Grid physical_grid(3, 3);

	std::cout << "TEST 1 - Index of (2,1) [correct: 7]: " << physical_grid.getIndex(2,1) << std::endl;
	std::cout << "TEST 2 - Value of (2,1) [correct: 298.15]: " << physical_grid.getValue(2,2) << std::endl;
	std::cout << "TEST 3 - Print the matrix using the printMatrix() method:" << std::endl;
	physical_grid.printMatrix();


	return 0;
}