#ifndef MAZE_DATA_H
#define MAZE_DATA_H

#include <vector>
#include <utility>
using namespace std;

struct MazeInfo {
    vector<vector<int> > maze;
    pair<int, int> start;
    pair<int, int> finish;
};

MazeInfo getMaze() {
    MazeInfo data;

    vector<int> row1;
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(1);
    row1.push_back(0);
    row1.push_back(0);

    vector<int> row2;
    row2.push_back(0);
    row2.push_back(0);
    row2.push_back(1);
    row2.push_back(0);
    row2.push_back(1);

    vector<int> row3;
    row3.push_back(1);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);

    vector<int> row4;
    row4.push_back(1);
    row4.push_back(1);
    row4.push_back(1);
    row4.push_back(0);
    row4.push_back(1);

    vector<int> row5;
    row5.push_back(0);
    row5.push_back(0);
    row5.push_back(0);
    row5.push_back(0);
    row5.push_back(0);

    data.maze.push_back(row1);
    data.maze.push_back(row2);
    data.maze.push_back(row3);
    data.maze.push_back(row4);
    data.maze.push_back(row5);

    data.start = make_pair(0, 0);
    data.finish = make_pair(4, 4);

    return data;
}

#endif
