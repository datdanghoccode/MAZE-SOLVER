#include "PathUtils.h"

#include <climits>

using namespace std;


vector<Cell> PathUtils::GetShortestPath(
    const vector<vector<Cell>>& allPaths)
{
    vector<Cell> shortestPath;

    int minStep = INT_MAX;

    for(const auto& path : allPaths)
    {
        int step = path.size() - 1;

        if(step < minStep)
        {
            minStep = step;
            shortestPath = path;
        }
    }

    return shortestPath;
}


int PathUtils::GetShortestStep(
    const vector<vector<Cell>>& allPaths)
{
    if(allPaths.empty())
    {
        return -1;
    }

    int minStep = INT_MAX;

    for(const auto& path : allPaths)
    {
        int step = path.size() - 1;

        if(step < minStep)
        {
            minStep = step;
        }
    }

    return minStep;
}


int PathUtils::GetTotalPath(
    const vector<vector<Cell>>& allPaths)
{
    return (int)allPaths.size();
}


vector<int> PathUtils::GetPathLengths(
    const vector<vector<Cell>>& allPaths)
{
    vector<int> lengths;

    for(const auto& path : allPaths)
    {
        lengths.push_back(path.size() - 1);
    }

    return lengths;
}
