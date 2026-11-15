#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <cmath>
#include "../include/physical_constrains.hpp"
#include "../include/physical_grid.hpp"


// CONSTRUCTOR

Grid::Grid (unsigned int nx, unsigned int ny):
nx(nx), ny(ny), len(nx*ny), data(nx*ny, 0) {
	if (!(nx >= 3 && ny >= 3)){
		throw std::invalid_argument("Number of points in rows and columns must be greater or equal to 3!");
	}

	// Initialization of the boundary points
	for(unsigned int j = 0; j < ny; ++j){
		if(j == 0 || j == (ny-1)){
			for(unsigned int i = 0; i < nx; ++i){
				data[flatToIndex(i,j)] = T_AMB;
			}
		} else {
			data[flatToIndex(0,j)] = T_AMB;
			data[flatToIndex(nx-1,j)] = T_AMB;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// PRIVATE METHODS

unsigned int Grid::flatToIndex(unsigned int i, unsigned int j) const {
	return j*nx + i;
}

unsigned int Grid::sparseToIndex(unsigned int i, unsigned int j) const {
	return (j-1)*(nx-2) + (i-1);
}

unsigned int Grid::coordinatesToIndex(double x, double y) const {
	return this->flatToIndex(std::round(x), std::round(y));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


// GENERAL METHODS

int Grid::getIndex (unsigned int x, unsigned int y) {
	if (x >= nx || y >= ny) {
		std::cerr << "Error: Coordinates exceeding grid limits!" <<std::endl;
		return -1;
	}
	return flatToIndex(x,y);
}

double Grid::getValue (unsigned int x, unsigned int y) {
	if (x >= nx || y >= ny) {
		std::cerr << "Error: Coordinates exceeding grid limits!" <<std::endl;
		return -1.0;
	}
	return data[flatToIndex(x,y)];
}

void Grid::setValue(unsigned int x, unsigned int y, double value) {
    if (x >= nx || y >= ny) {
        throw std::out_of_range("Invalid grid coordinates");
    }

    data[flatToIndex(x,y)] = value;
}

int Grid::getTotRows() {
	return ny;
}

int Grid::getTotColumns() {
	return nx;
}

void Grid::printMatrix() {
	std::cout << "Grid matrix: " << std::endl;
	for(unsigned int j = 0; j < ny; ++j){
		for(unsigned int i = 0; i < nx; ++i){
			std::cout << std::setw(8) << data[flatToIndex(i,j)];
		}
		std::cout << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// TEMPERATURE INFORMATIONS

double Grid::getMeanTemperature(){
	double sum = std::accumulate(data.begin(), data.end(), 0.0);
	return sum / data.size();
}

TemperatureInfo Grid::getMinTemperature(){
	double min = data[0];
	unsigned int ind = 0;

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
	unsigned int ind = 0;

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

//////////////////////////////////////////////////////////////////////////////////////////////////////


void Grid::computeSMTemperature (Source source) {
	if (this->len == 9){
		this->data[4] = T_AMB + (source.getEnergy(0.8, 0.5)) / (2 * K * ((1.0 / (0.8 * 0.8)) + (1.0 / (0.5 * 0.5))) + H);
	} else {
		return throw std::runtime_error("Error: The specified grid is not a 3x3 grid. Remember, this method works just for simple 3x3 grids!");
	}
}