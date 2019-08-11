#include "cli.h"

#include <iostream>
#include <chrono>

#include "../polycube/puzzle.h"

#include "read.h"
#include "parse.h"
#include "format.h"

long long currentTime () {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int main (int argc, char** argv) {
	auto puzzleData = read::commandLine(argc, argv);
	auto puzzle = parse::puzzle(puzzleData);

	std::cout << "\nInitiating search for solutions.\n";

	puzzle.initialize();

	std::cout << "Searching...\n";
	
	auto startTime = currentTime();
	auto solutions = puzzle.solve();
	auto endTime = currentTime();

	std::cout << "Search completed in " << endTime - startTime << " millisecond" << (endTime - startTime == 1 ? "" : "s") << ".\n\n";
	std::cout << format::solutions(solutions, 10);

	return 0;
}
