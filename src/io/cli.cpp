#include "cli.h"

#include <iostream>
#include <exception>

#include "puzzle.h"

#include "read.h"
#include "parse.h"
#include "format.h"
#include "stopwatch.h"


int main (int argc, char** argv) {
    Stopwatch stopwatch;
    Puzzle<3> puzzle;
    int solutionLimit = 100, printLimit = 10;
    bool color = false;

    try {
        puzzle = parse::puzzle(read::commandLine(argc, argv, color, solutionLimit, printLimit));
    }
    catch (std::exception& e) {
        std::cout << e.what();
        std::cout << "Solution search aborted.\n";
        return 1;
    }

    std::cout << "Initiating search for solutions.\n";

    puzzle.initialize();

    std::cout << "Searching...\n";
    
    stopwatch.start();
    auto solutions = puzzle.solve(solutionLimit);
    stopwatch.stop();

    std::cout << "Search completed in " << format::countable(stopwatch.time(), "millisecond") << ".\n\n";
    std::cout << format::solutions(solutions, color, solutionLimit, printLimit);

    return 0;
}
