#pragma once

#include "exact_cover.h"

namespace exact_cover {
    std::vector<Solution> sat (const Problem& problem, int solutionLimit);
}