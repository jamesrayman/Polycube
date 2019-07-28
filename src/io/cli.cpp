#include "cli.h"

#include <iostream>

#include "../util/vector.h"
#include "../util/matrix.h"
#include "../util/lattice.h"
#include "../util/util.h"
#include "../polycube/polycube.h"
#include "../polycube/polycube_list.h"
#include "../polycube/board.h"
#include "../polycube/puzzle.h"

#include "read.h"
#include "parse.h"
#include "format.h"

int main (int argc, char** argv) {
	auto puzzleData = read::commandLine(argc, argv);
	// auto puzzle = parse::puzzle(puzzleData);

	std::cout << "\nInitiating search for solutions.\n";

	// auto solutions = puzzle.solve();

	std::cout << "Search complete.\n\n";
	// std::cout << format::solutions(solutions);

	return 0;
}
