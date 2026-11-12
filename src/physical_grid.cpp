#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include "../include/physical_constrains.hpp"
#include "../include/physical_grid.hpp"


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
	if (x >= nx || y >= ny) {
		std::cerr << "Coordinates exceding grid limits" <<std::endl;
	}
	return index(x,y);
}

double Grid::getValue (unsigned int x, unsigned int y) {
	if (x >= nx || y >= ny) {
		std::cerr << "Coordinates exceding grid limits" <<std::endl;
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


// TEMPERATURE INFORMATIONS

double Grid::getMeanTemperature(){
	double sum = std::accumulate(data.begin(), data.end(), 0.0);
	return sum / data.size();
}

TemperatureInfo Grid::getMinTemperature(){
	double min = data[0];
	int ind = 0;

	for (int i = 1; i < data.size(); ++i) {
		if (data[i] < min) {
			min = data[i];
			ind = i;
		}
	}

	TemperatureInfo t_min = {min, ind};
	return t_min;
}

TemperatureInfo Grid::getMaxTemperature(){
	double max = data[0];
	int ind = 0;

	for (int i = 1; i < data.size(); ++i) {
		if (data[i] > max) {
			max = data[i];
			ind = i;
		}
	}

	TemperatureInfo t_max = {max, ind};
	return t_max;
}

double Grid::getDeltaTemperature(){
	return this->getMaxTemperature().value - T_AMB;
}