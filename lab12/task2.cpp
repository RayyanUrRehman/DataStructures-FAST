#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
using Grid = vector<vector<T>>;

int NumberOfIslands(Grid<bool>& grid) {
    const int directions[4][2] = {
        {-1,  0},
        { 1,  0},
        { 0, -1},
        { 0,  1}
    };

    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid.front().size());

    int islands = 0;

    function<void(int, int)> DFS = [&](int i, int j) -> void {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
            return;
        }

        grid[i][j] = false;

        for (int k = 0; k < 4; k++) {
            DFS(i + directions[k][0], j + directions[k][1]);
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                DFS(i, j);
                islands++;
            }
        }
    }

    return islands;
}

int main() {
    Grid<bool> grid = {
        {1, 0},
        {0, 1},
        {1, 1}
    };

    int numberOfIslands = NumberOfIslands(grid);
    cout << "Number of islands: " << numberOfIslands << endl;

    return 0;
}