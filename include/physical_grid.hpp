#ifndef PHYSICAL_GRID_HPP
#define PHYSICAL_GRID_HPP

#import <iostream>
#include <iomanip>
#import "physical_constrains.hpp"

class Grid {
private:
	unsigned int nx;
	unsigned int ny;
	unsigned int len;
	std::vector<double> data;

	// Method that returns the index of the point (i,j) in the vector
	unsigned int index(unsigned int i, unsigned int j) const {
		return i*nx + j;
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
};

#endif