#ifndef validator_h
#define validator_h

#include <vector>

class Validator {
public:
    
    static bool IsValidMove(int x, int y, int rows, int cols, 
                            const std::vector<std::vector<int>>& maze, 
                            const std::vector<std::vector<bool>>& visited) {
        
        // 1. Kiểm tra ranh giới: Không được đi ra ngoài bản đồ
        if (x < 0 || x >= rows || y < 0 || y >= cols) {
            return false;
        }

        // 2. Kiểm tra vật cản: Không được đi vào tường (giá trị 1)
        if (maze[x][y] == 1) {
            return false;
        }

        // 3. Kiểm tra trạng thái: Không đi lại vào ô đã qua để tránh vòng lặp (loop)
        if (visited[x][y]) {
            return false;
        }

        return true;
    }
};

#endif // validator_h
