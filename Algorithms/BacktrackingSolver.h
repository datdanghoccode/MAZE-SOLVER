#pragma once

#include <vector>
#include <string>
#include <fstream>

// Cấu trúc lưu tọa độ của một ô trong mê cung
struct Cell
{
    int row;
    int col;

    Cell()
    {
        row = 0;
        col = 0;
    }

    Cell(int r, int c)
    {
        row = r;
        col = c;
    }

    bool operator==(const Cell& other) const
    {
        return row == other.row &&
               col == other.col;
    }
};

// Lớp BacktrackingSolver
// Chức năng:
//  - Tìm một đường đi
//  - Tìm tất cả đường đi
class BacktrackingSolver
{
public:

    using Maze = std::vector<std::vector<int>>;

    // Constructor
    BacktrackingSolver();

    // Thiết lập dữ liệu

    void SetMaze(const Maze& maze);

    void SetStart(const Cell& start);

    void SetEnd(const Cell& end);

    // Thuật toán

    // Tìm một đường đi
    bool Solve();

    // Tìm tất cả đường đi
    bool SolveAll();

    // Lấy kết quả
    const std::vector<Cell>& GetPath() const;

    const std::vector<std::vector<Cell>>& GetAllPaths() const;

    // Thống kê

    int GetStepCount() const;

    int GetBacktrackCount() const;

    int GetFoundPathCount() const;
    // Hiển thị

    void PrintMaze() const;

    void PrintCurrentPath() const;

    void PrintAllPaths() const;

    void PrintStatistics() const;

// Xuất kết quả

void ExportResult(const std::string& fileName) const;

private:

    // Dữ liệu mê cung

    Maze maze;

    std::vector<std::vector<bool>> visited;

    // Điểm bắt đầu và kết thúc

    Cell start;

    Cell end;

    // Đường đi hiện tại

    std::vector<Cell> currentPath;

    // Đường đi tìm được

    std::vector<Cell> resultPath;

    // Danh sách tất cả đường đi

    std::vector<std::vector<Cell>> allPaths;

    // Thống kê

    int stepCount;

    int backtrackCount;

    int foundPathCount;

    // Hướng di chuyển

    static const int dr[4];

    static const int dc[4];

    // Hàm nội bộ

    bool DFS(int row, int col);

    void DFSAll(int row, int col);

    bool IsValid(int row, int col) const;

    bool IsDestination(int row, int col) const;

    void SaveCurrentPath();

    void Backtrack(int row, int col);

    void ResetSolver();
};