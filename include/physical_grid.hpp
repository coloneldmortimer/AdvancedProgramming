#ifndef PHYSICAL_GRID_HPP
#define PHYSICAL_GRID_HPP

#include <iostream>
#include <iomanip>
#include "physical_constrains.hpp"
#include "temperature_info.hpp"

class Grid {
private:
	unsigned int nx;
	unsigned int ny;
	unsigned int len;
	std::vector<double> data;

	// Method that returns the index of the point (i,j) in the vector
	unsigned int index(unsigned int i, unsigned int j) const {
		return j*nx + i;
	}

	// Method that returns the index of the point (i,j) in the vector
	unsigned int InternalPointsIndex(unsigned int i, unsigned int j) const {
		return (j-1)*(nx-2) + (i-1);
	}

public:
	// Constructor
	Grid (unsigned int nx, unsigned int ny);

	// Method that returns the index of the point (x,y) in the vector
	unsigned int getIndex (unsigned int x, unsigned int y);

	// Method that returns the value of the point (x,y) of the matrix
	double getValue (unsigned int x, unsigned int y);

	// Method that returns the total number of rows
	int getTotRows();

	// Method that returns the total number of columns
	int getTotColumns();

	// Method for printing the vector in matrix form
	void printMatrix();



	// Method that returns the minimum temperature (and its index) of the solar panel grid
	// getMinTemperature().value for minimum temperature
	// getMinTemperature().index fir minimum temperature index
	TemperatureInfo getMinTemperature();

	// Method that returns the maximum temperature (and its index) of the solar panel grid
	// getMaxTemperature().value for maximum temperature
	// getMaxTemperature().index fir maximum temperature index
	TemperatureInfo getMaxTemperature();

	// Method that returns the mean temperature of the solar panel grid
	double getMeanTemperature();

	// Method that returns the difference between the maximum and the ambient temperature of the solar panel grid
	double getDeltaTemperature();
};

#endif