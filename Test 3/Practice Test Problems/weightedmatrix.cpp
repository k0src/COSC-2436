#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class WeightedGraph {
private:
    struct DSU {
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

        vector<int> parent, rank;
    };


    vector<vector<int>> matrix;
    int n_vertices;
public:
    WeightedGraph(int n_vertices) : n_vertices(n_vertices) {
        matrix.resize(n_vertices, vector<int>(n_vertices, 0));
    }

    void add_edge(int u, int v, int weight) {
        if (u < 0 || u >= n_vertices || v < 0 || v >= n_vertices) return;

        matrix[u][v] = weight;
        matrix[v][u] = weight;
    }

    void remove_edge(int u, int v) {
        if (u < 0 || u >= n_vertices || v < 0 || v >= n_vertices) return;

        matrix[u][v] = 0;
        matrix[v][u] = 0;
    }

    bool edge_exists(int u, int v) {
        if (u < 0 || u >= n_vertices || v < 0 || v >= n_vertices) return false;

        if (matrix[u][v] != 0) {
            return true;
        }

        return false;
    }

    int edge_weight(int u, int v) {
        if (u < 0 || u >= n_vertices || v < 0 || v >= n_vertices) return -1;

        if (matrix[u][v] != 0) {
            return matrix[u][v];
        }
        
        return -1;
    }

    void DFS(int root) {
        vector<bool> visited(n_vertices, false);
        stack<int> st;
        st.push(root);

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (visited[u]) continue;

            cout << u << " ";
            visited[u] = true;

            for (int v = n_vertices - 1; v >= 0; v--) {
                if (matrix[u][v] != 0 && !visited[v]) {
                    st.push(v);
                }
            }
        }
    }

    void BFS(int root) {
        vector<bool> visited(n_vertices, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v = 0; v < n_vertices; v++) {
                if (matrix[u][v] != 0 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void MST() {
        DSU dsu(n_vertices + 1);
        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < n_vertices; i++) {
            for (int j = i + 1; j < n_vertices; j++) {
                if (matrix[i][j] != 0) {
                    edges.emplace_back(matrix[i][j], i, j); // weight, u, v
                }
            }
        }

        sort(edges.begin(), edges.end());

        for (auto& e : edges) {
            int u = get<1>(e);
            int v = get<2>(e);

            if (dsu.find(u) != dsu.find(v)) {
                cout << u << " " << v << endl;
                dsu.unite(u, v);
            }
        }
    }
};

int main()
{
    WeightedGraph g(6);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 4, 3);
    g.add_edge(2, 3, 5);
    g.add_edge(2, 5, 5);

    cout << g.edge_exists(1, 2) << endl;
    cout << g.edge_exists(1, 5) << endl;

    g.DFS(1);
    cout << endl;
    g.BFS(1);
    cout << endl;
    g.MST();

    return 0;
}