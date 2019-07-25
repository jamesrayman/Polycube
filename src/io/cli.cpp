#include "cli.h"

#include <iostream>

#include "../util/vector.h"
#include "../util/matrix.h"
#include "../util/lattice.h"
#include "../util/util.h"
#include "../polycube/polycube.h"
#include "../polycube/polycube_list.h"
#include "../polycube/board.h"

#include "util.h"
#include "parser.h"

int main (int argc, char** argv) {
	std::cout << util::readCommandLine(argc, argv) << "\n";

	return 0;
}
