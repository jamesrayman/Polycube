#include "cli.h"

#include <iostream>
#include <exception>
#include <chrono>

#include "puzzle.h"

#include "read.h"
#include "parse.h"
#include "format.h"

long long currentTime () {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int main (int argc, char** argv) {
	Puzzle<3> puzzle;
	int solutionLimit, printLimit;

	try {
		puzzle = parse::puzzle(read::commandLine(argc, argv, solutionLimit, printLimit));
	}
	catch (std::exception& e) {
		std::cout << e.what();
		return 1;
	}

	std::cout << "\nInitiating search for solutions.\n";

	puzzle.initialize();

	std::cout << "Searching...\n";
	
	auto startTime = currentTime();
	auto solutions = puzzle.solve(solutionLimit);
	auto endTime = currentTime();

	std::cout << "Search completed in " << format::countable(endTime - startTime, "millisecond") << ".\n\n";
	std::cout << format::solutions(solutions, printLimit);

	return 0;
}
