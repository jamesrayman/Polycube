#include <iostream>

#include "util/vector.h"
#include "util/matrix.h"
#include "util/lattice.h"

int main () {
	Lattice<int, 2> lattice { { 1, 2, 3 }, { 4, 5, 6 } };

	lattice = Matrix<3>::planeRotation(0, 1, 3) * lattice;

	for (int i = 0; i < 2; i++) {
		std::cout << lattice.shape()[i] << " ";
	}
	std::cout << "\n\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << lattice[{ i, j }] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
