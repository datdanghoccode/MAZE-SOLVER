#include "BacktrackingSolver.h"

#include <algorithm>

using namespace std;

const int BacktrackingSolver::dr[4] =
{
    -1, 1, 0, 0
};

const int BacktrackingSolver::dc[4] =
{
     0, 0, -1, 1
};

BacktrackingSolver::BacktrackingSolver()
{
    ResetSolver();
}

void BacktrackingSolver::SetMaze(const Maze& inputMaze)
{
    maze = inputMaze;

    visited.clear();

    if(maze.empty())
    {
        return;
    }

    visited.assign(
        maze.size(),
        vector<bool>(
            maze[0].size(),
            false
        )
    );
}

void BacktrackingSolver::SetStart(const Cell& s)
{
    start = s;
}

void BacktrackingSolver::SetEnd(const Cell& e)
{
    end = e;
}

void BacktrackingSolver::ResetSolver()
{
    currentPath.clear();
    resultPath.clear();
    allPaths.clear();

    stepCount = 0;
    backtrackCount = 0;
    foundPathCount = 0;

    for(size_t i = 0; i < visited.size(); i++)
    {
        fill(
            visited[i].begin(),
            visited[i].end(),
            false
        );
    }
}

bool BacktrackingSolver::Solve()
{
    ResetSolver();

    if(!IsValid(start.row, start.col))
    {
        return false;
    }

    return DFS(
        start.row,
        start.col
    );
}

bool BacktrackingSolver::SolveAll()
{
    ResetSolver();

    if(!IsValid(start.row,start.col))
    {
        return false;
    }

    DFSAll(
        start.row,
        start.col
    );

    return !allPaths.empty();
}

bool BacktrackingSolver::DFS(int row, int col)
{
    if(!IsValid(row, col))
    {
        return false;
    }

    visited[row][col] = true;

    currentPath.push_back(
        Cell(row, col)
    );

    stepCount++;

    if(IsDestination(row, col))
    {
        resultPath = currentPath;

        foundPathCount++;

        return true;
    }

    for(int i = 0; i < 4; i++)
    {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];

        if(DFS(nextRow, nextCol))
        {
            return true;
        }
    }

    Backtrack(row, col);

    return false;
}

void BacktrackingSolver::DFSAll(int row, int col)
{
    if(!IsValid(row, col))
    {
        return;
    }

    visited[row][col] = true;

    currentPath.push_back(
        Cell(row, col)
    );

    stepCount++;

    if(IsDestination(row, col))
    {
        SaveCurrentPath();

        foundPathCount++;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            DFSAll(
                nextRow,
                nextCol
            );
        }
    }

    Backtrack(row, col);
}

bool BacktrackingSolver::IsValid(int row, int col) const
{
    if(row < 0)
    {
        return false;
    }

    if(col < 0)
    {
        return false;
    }

    if(row >= (int)maze.size())
    {
        return false;
    }

    if(col >= (int)maze[0].size())
    {
        return false;
    }

    if(maze[row][col] == 1)
    {
        return false;
    }

    if(visited[row][col])
    {
        return false;
    }

    return true;
}

bool BacktrackingSolver::IsDestination(int row, int col) const
{
    return row == end.row &&
           col == end.col;
}

void BacktrackingSolver::SaveCurrentPath()
{
    allPaths.push_back(currentPath);

    if(resultPath.empty() ||
        currentPath.size() < resultPath.size())
    {
        resultPath = currentPath;
    }
}

void BacktrackingSolver::Backtrack(int row, int col)
{
    if(!currentPath.empty())
    {
        currentPath.pop_back();
    }

    visited[row][col] = false;

    backtrackCount++;
}

const std::vector<Cell>& BacktrackingSolver::GetPath() const
{
    return resultPath;
}

const std::vector<std::vector<Cell>>& BacktrackingSolver::GetAllPaths() const
{
    return allPaths;
}

int BacktrackingSolver::GetStepCount() const
{
    return stepCount;
}

int BacktrackingSolver::GetBacktrackCount() const
{
    return backtrackCount;
}

int BacktrackingSolver::GetFoundPathCount() const
{
    return foundPathCount;
}