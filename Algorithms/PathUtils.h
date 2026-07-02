#pragma once

#include <vector>
#include "BacktrackingSolver.h"

class PathUtils
{
public:

    static std::vector<Cell> GetShortestPath(
        const std::vector<std::vector<Cell>>& allPaths);

    static int GetShortestStep(
        const std::vector<std::vector<Cell>>& allPaths);

    static int GetTotalPath(
        const std::vector<std::vector<Cell>>& allPaths);

    static std::vector<int> GetPathLengths(
        const std::vector<std::vector<Cell>>& allPaths);
};
