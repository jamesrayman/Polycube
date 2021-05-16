#pragma once

#include "exact_cover.h"

namespace exact_cover {
    std::vector<Solution> dlx (const Problem& problem, int solutionLimit);
}