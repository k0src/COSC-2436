#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dfs(const vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visit) {
    int ROWS = grid.size();
    int COLS = grid[0].size();

    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visit.count({r, c}) || grid[r][c] == 1) {
        return 0;
    }

    if (r == ROWS - 1 && c == COLS - 1) {
        return 1;
    }

    visit.insert({r, c});

    int count = 0;
    count += dfs(grid, r + 1, c, visit); // down
    count += dfs(grid, r - 1, c, visit); // up
    count += dfs(grid, r, c + 1, visit); // right
    count += dfs(grid, r, c - 1, visit); // left

    visit.erase({r, c});
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    set<pair<int, int>> visit;

    cout << dfs(grid, 0, 0, visit);
    return 0;
}
