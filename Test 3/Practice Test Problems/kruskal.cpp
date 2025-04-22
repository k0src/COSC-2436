#include "help.h"

using namespace std;

using Edge = tuple<int, int, int>; // From, To, Weight
using AdjList = unordered_map<int, list<Edge>>; // Vertex, list of edges

//========= KRUSKAL'S ALGORITHM ==========

class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0) {
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
private:
    vector<int> parent;
    vector<int> rank;
};

vector<Edge> mstEdges(AdjList& adj, int n_vertices) {
    DSU dsu(n_vertices + 1);
    vector<Edge> res;
    vector<Edge> edge_list;

    for (auto& [_, edges] : adj) {
        edge_list.insert(edge_list.end(), edges.begin(), edges.end());
    }

    std::sort(edge_list.begin(), edge_list.end(),
              [](const Edge& a, const Edge& b) 
              { return get<2>(a) < get<2>(b); });


    for (auto& e : edge_list) {
        int u = get<0>(e);
        int v = get<1>(e);

        if (dsu.find(u) != dsu.find(v)) {
            res.push_back(e);
            dsu.unite(u, v);
        }
    }

    return res;
}

int main()
{
    AdjList adj = 
    {
        {1, {{1, 2, 6}, {1, 5, 5}}},
        {2, {{2, 1, 6}, {2, 3, 4}, {2, 5, 12}}}, 
        {3, {{3, 2, 4}, {3, 4, 8}, {3, 5, 10}}}, 
        {4, {{4, 3, 8}, {4, 6, 9}, {4, 7, 8}, {4, 8, 5}}}, 
        {5, {{5, 1, 5}, {5, 2, 12}, {5, 3, 10}, {5, 6, 10}}},
        {6, {{6, 5, 10}, {6, 4, 9}, {6, 7, 5}}}, 
        {7, {{7, 4, 8}, {7, 6, 5}, {7, 8, 6}}}, 
        {8, {{8, 4, 5}, {8, 7, 6}}}
    };

    for (auto& e : mstEdges(adj, 8)) {
        cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
    }

    return 0;
}