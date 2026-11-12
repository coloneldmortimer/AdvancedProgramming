#import <iostream>
#include <iomanip>
#import "../include/physical_constrains.hpp"
#import "../include/physical_grid.hpp"


Grid::Grid (unsigned int nx, unsigned int ny): nx(nx), ny(ny), len(nx*ny), data(nx*ny, 0) {
	for(unsigned int i = 0; i < nx; ++i){
		if(i == 0 || i == (nx-1)){
			for(unsigned int j = 0; j < ny; ++j){
				data[index(i,j)] = T_AMB;
			}
		} else {
			data[index(i,0)] = T_AMB;
			data[index(i,nx-1)] = T_AMB;
		}
	}
}

unsigned int Grid::getIndex (unsigned int x, unsigned int y) {
	if (x > ny) {
		std::cerr << "Overflow" <<std::endl;
	}
	return index(x,y);
}

double Grid::getValue (unsigned int x, unsigned int y) {
	if (x > ny) {
		std::cerr << "Overflow" <<std::endl;
	}
	return data[index(x,y)];
}

int Grid::getTotRows() {
	return nx;
}

int Grid::getTotColumns() {
	return ny;
}

void Grid::printMatrix() {
	std::cout << "Grid matrix: " << std::endl;
	for(unsigned int i = 0; i < nx; ++i){
		for(unsigned int j = 0; j < nx; ++j){
			std::cout << std::setw(8) << data[index(i,j)];
		}
		std::cout << std::endl;
	}
}