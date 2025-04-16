#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

// Kruskal's algorithm to compute MST
// Returns a list of edges in the MST using lazy evaluation

using Edge = std::tuple<int, int, int>;  // from, to, weight
using AdjList = std::unordered_map<int, std::list<Edge>>; // Vertex, list of edges

class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
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

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

std::vector<Edge> MST(AdjList& adj, int n_vertices) {
    DSU dsu(n_vertices);
    std::vector<Edge> res;
    std::vector<Edge> edge_list;

    for (auto& [_, edges] : adj) {
        edge_list.insert(edge_list.end(), edges.begin(), edges.end());
    }

    std::sort(edge_list.begin(), edge_list.end(), [](const Edge& a, const Edge& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    for (auto& e : edge_list) {
        int u = std::get<0>(e);
        int v = std::get<1>(e);

        if (dsu.find(u) != dsu.find(v)) {
            res.push_back(e);
            dsu.unite(u, v);
        }
    }
    return res;
}

int main() 
{
    AdjList adj;
    adj[1] = { {1, 2, 10}, {1, 3, 1}, {1, 4, 4} };
    adj[2] = { {2, 1, 10}, {2, 5, 0}, {2, 3, 3} };
    adj[3] = { {3, 1, 1}, {3, 6, 8}, {3, 2, 3}, {3, 4, 2} };
    adj[4] = { {4, 1, 4}, {4, 6, 2}, {4, 7, 7}, {4, 3, 2} };
    adj[5] = { {5, 2, 0}, {5, 6, 1}, {5, 8, 8} };
    adj[6] = { {6, 5, 1}, {6, 3, 8}, {6, 8, 9}, {6, 7, 6}, {6, 4, 2} };
    adj[7] = { {7, 4, 7}, {7, 6, 6}, {7, 8, 12} };
    adj[8] = { {8, 5, 8}, {8, 6, 9}, {8, 7, 12} };

    std::vector<Edge> edges = MST(adj, 8);
    int totalWeight = 0;

    std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : edges) {
        std::cout << std::get<0>(edge) << " - " << std::get<1>(edge) << " : " << std::get<2>(edge) << std::endl;
        totalWeight += std::get<2>(edge);
    }

    std::cout << "Total weight of MST: " << totalWeight << std::endl;

    return 0;
}