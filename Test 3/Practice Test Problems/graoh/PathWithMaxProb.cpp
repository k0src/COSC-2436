#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <queue>

using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<double> probs(n, 0.0);

    priority_queue<pair<double, int>> pq;

    probs[start_node] = 1.0;
    pq.push({1.0, start_node});

    while (!pq.empty()) {
        double prob = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == end_node) return prob;

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == node) {
                int v = edges[i][1];

                if (prob * succProb[i] > probs[v]) {
                    probs[v] = prob * succProb[i];
                    pq.push({probs[v], v});
                }
            } else if (edges[i][1] == node) {
                int v = edges[i][0];

                if (prob * succProb[i] > probs[v]) {
                    probs[v] = prob * succProb[i];
                    pq.push({probs[v], v});
                }
            }
        }
    }

    return 0.0;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {{2,3},{1,2},{3,4},{1,3},{1,4},{0,1},{2,4},{0,4},{0,2}};
    vector<double> succProb = {0.06,0.26,0.49,0.25,0.2,0.64,0.23,0.21,0.77};
    int start_node = 0;
    int end_node = 3;
    cout << maxProbability(n, edges, succProb, start_node, end_node);
    return 0;
}