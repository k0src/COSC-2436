#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class WeightedAdjMatrix {
private:
    struct DSU {
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }

        vector<int> parent, rank;
    };

    vector<vector<int>> matrix;

    void resize_matrix(int size) {
        for (auto& row : matrix) {
            row.resize(size, 0);
        }
        matrix.resize(size, vector<int>(size, 0));
    }
public:
    void add_edge(int u, int v, int weight) {
        if (has_edge(u, v)) return;

        if (max(u, v) >= matrix.size()) {
            resize_matrix(max(u, v) + 1);
        }

        matrix[u][v] = weight;
        matrix[v][u] = weight;
    }
    
    void remove_edge(int u, int v) {
        if (!has_edge(u, v)) return;
        
        matrix[u][v] = 0;
        matrix[v][u] = 0;
    }

    bool has_edge(int u, int v) {
        if (max(u, v) >= matrix.size()) return false;
        return matrix[u][v] != 0;
    }

    int get_weight(int u, int v) {
        if (max(u, v) >= matrix.size()) return false;
        return matrix[u][v];
    }

    // Kruskal's
    vector<vector<int>> MST() {
        int n = matrix.size();
        DSU dsu(n);
        vector<vector<int>> edges;
        vector<vector<int>> mst;

        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (matrix[u][v] != 0) {
                    edges.push_back({u, v, matrix[u][v]});
                }
            }
        }

        sort(edges.begin(), edges.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });
        
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (dsu.find(u) != dsu.find(v)) {
                mst.push_back(e);
                dsu.unite(u, v);
            }
        }
        return mst;
    }

    vector<vector<int>> MSTPrims() {
        int n = matrix.size();
        vector<bool> visited(n, false);

        using edge = tuple<int, int, int>;
        auto compare = [](const edge& a, const edge& b) {
            return get<2>(a) > get<2>(b);
        };

        priority_queue<edge, vector<edge>, decltype(compare)> pq;
        vector<vector<int>> mst;

        visited[0] = true;

        for (int v = 0; v < n; v++) {
            if (matrix[0][v] != 0) {
                pq.push({0, v, matrix[0][v]});
            }
        }

        while (!pq.empty()) {
            auto [u, v, weight] = pq.top();
            pq.pop();
            
            if (visited[v]) continue;
            
            visited[v] = true;
            mst.push_back({u, v, weight});
            
            for (int next = 0; next < n; next++) {
                if (!visited[next] && matrix[v][next] != 0) {
                    pq.push({v, next, matrix[v][next]});
                }
            }
        }
        return mst;
    }
};

int main()
{
    WeightedAdjMatrix graph;
    graph.add_edge(0, 1, 2);    
    graph.add_edge(0, 2, 4);    
    graph.add_edge(1, 2, 3);
    graph.add_edge(1, 3, 5);
    graph.add_edge(2, 3, 1);
    graph.add_edge(2, 4, 2);
    graph.add_edge(3, 4, 1);

    for (const auto& edge : graph.MST()) {
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    }

    return 0;
}