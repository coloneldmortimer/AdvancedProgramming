#ifndef PHYSICAL_GRID_HPP
#define PHYSICAL_GRID_HPP

#include <iostream>
#include <iomanip>
#include "temperature_info.hpp"

class Grid {
private:
	unsigned int nx;
	unsigned int ny;
	unsigned int len;
	std::vector<double> data;

	// Method that returns the index in the vector of the point (i,j) of the flat grid
	unsigned int flatToIndex(unsigned int i, unsigned int j) const;

	// Method that returns the index in the vector of the point (i,j) of the sparse matrix
	unsigned int sparseToIndex(unsigned int i, unsigned int j) const;

	// Method that returns the approximated index in the vector of the point (x,y)
	unsigned int coordinatesToIndex(double x, double y) const;

public:
	// Constructor
	// nx: number of columns of the grid (insert an integer value greater or equal to 3)
	// ny: number of rows of the grid (insert an integer value greater or equal to 3)
	Grid (unsigned int nx, unsigned int ny);

	// Method that from returns the index of the point (x,y) of the flat matrix in the vector
	int getIndex (unsigned int x, unsigned int y);

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



	// Compute the temperature of the central point of a simple model (3x3 grid) - Avaiable for 3x3 models only
	void computeSMTemperature (Source source);
};

#endif