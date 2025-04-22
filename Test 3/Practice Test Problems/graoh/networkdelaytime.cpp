#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <queue>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> min_times(n + 1, INT_MAX);
    priority_queue<pair<int, int>> pq; // min time, node

    min_times[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int current_time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < times.size(); i++) {
            if (times[i][0] == u) {
                int v = times[i][1];
                int time = times[i][2];

                if (current_time + time < min_times[v]) {
                    min_times[v] = current_time + time;
                    pq.push({min_times[v], v});
                }
            }
        }
    }

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (min_times[i] == INT_MAX) return -1;
        max_time = max(max_time, min_times[i]);
    }
    return max_time;
}

int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    cout << networkDelayTime(times, n, k);
    return 0;
}