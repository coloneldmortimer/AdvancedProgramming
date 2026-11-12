# Project for the 'Advanced Programming for Computational Sciences' course offered in SISSA
## Group members: Mattia Siega, Alessio Scatigna
### Project track: [1 - Solar panel](https://github.com/pcafrica/apcs_2026-2027/blob/main/projects/project_1_solar_panel.md)

Develop a C++ program for computing the steady-state temperature of a simplified photovoltaic panel. The work starts from a transparent standard-library implementation and grows into a reusable library with sparse solvers, tests, CMake, Python bindings, and comparison with SciPy.

No previous knowledge of partial differential equations, numerical grids, sparse matrices, third-party C++ libraries, or Python bindings is assumed. The model and the numerical formulas needed for the project are specified below.


### Tests
The first test is intended to try the general functionality of the class 'Grid' which is used to represent the solar panel grid.  

In the */script* folder a script named *test.sh* is provided to run this and eventually all the future tests; it can be executed with the command `./test.sh` from the terminal.
It will compile the *1-test_class.cpp*, save the build in the *build/tests* folder and execute it.