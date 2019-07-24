#include <iostream>

#include "util/vector.h"
#include "util/matrix.h"
#include "util/lattice.h"
#include "util/util.h"

int main () {
	Lattice<int, 3> a { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
	Lattice<int, 3> b { { { 3, 4 }, { 7, 8 } }, { { 1, 2 }, { 5, 6 } } };

	//a = Matrix<4>::planeRotation(0, 1, 1) * a;

	for (const auto& i : a.allPositions()) {
		std::cout << a[i] << " ";
	} 
	std::cout << "\n";

	std::cout << (a == b) << "\n";
	

	return 0;
}
