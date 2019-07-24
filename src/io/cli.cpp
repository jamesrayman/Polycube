#include "cli.h"

#include <iostream>

#include "../util/vector.h"
#include "../util/matrix.h"
#include "../util/lattice.h"
#include "../util/util.h"
#include "../polycube/block.h"
#include "../polycube/board.h"

int main (int argc, char** argv) {
	Lattice<int, 3> a { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
	Lattice<int, 3> b { { { 3, 4 }, { 7, 8 } }, { { 1, 2 }, { 5, 6 } } };

	for (const auto& i : a.allPositions()) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";

	std::cout << (a == b) << "\n";
	
	std::cout << argv[0] << "\n";

	return 0;
}
