#include <iostream>
#include "../src/physical_grid.cpp"

int main() {
	std::cout << "TEST ERROR OF CHOOSING A TOO SMALL GRID\n" << std::endl;
	Grid physical_grid(0, 3);
	return 0;
}