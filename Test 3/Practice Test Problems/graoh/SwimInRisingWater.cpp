#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <queue>

using namespace std;

int swimInWater(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> elevations(rows, vector<int>(cols, INT_MAX));
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; // time, (i, j)
    
    elevations[0][0] = grid[0][0];
    pq.push({elevations[0][0], {0, 0}});

    int total_time = 0;

    while (!pq.empty()) {
        int elevation = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if (i == rows - 1 && j == cols - 1) {
            return elevation;
        }

        for ()
    }


}

int main()
{
    vector<vector<int>> grid = {{0,2},{1,3}};
    cout << swimInWater(grid);
    return 0;
}