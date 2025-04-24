#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class AdjMatrix {
private:
    vector<vector<int>> matrix;

    void resize_graph(int size) {
        for (auto& row : matrix) {
            row.resize(size, 0);
        }
        matrix.resize(size, vector<int>(size, 0));
    }

public:
    void add_edge(int u, int v) {
        if (has_edge(u, v)) return;

        if (max(u, v) >= matrix.size()) {
            resize_graph(max(u, v) + 1);
        }

        matrix[u][v] = 1;
    }

    void remove_edge(int u, int v) {
        if (!has_edge(u, v)) return;

        matrix[u][v] = 0;
    }

    bool has_edge(int u, int v) {
        if (max(u, v) >= matrix.size()) return false;

        return matrix[u][v] == 1;
    }

    void DFS(int start) {
        int n = matrix.size();
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(start);

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (visited[u]) continue;
            visited[u] = true;

            cout << u << " ";

            for (int i = n - 1; i>=0; i--) {
                if (matrix[u][i] != 0 && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }

    void BFS(int start) {
        int n = matrix.size();
    }
};

int main()
{
    AdjMatrix graph;
    graph.add_edge(0, 1);
    graph.add_edge(0, 3);
    graph.add_edge(0, 4);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 5);
    graph.add_edge(3, 4);
    graph.add_edge(3, 5);
    graph.add_edge(4, 0);
    graph.add_edge(4, 2);
    graph.add_edge(4, 5);
    graph.add_edge(5, 0);

    graph.remove_edge(1, 3);

    cout << graph.has_edge(5, 0) << endl;
    cout << graph.has_edge(1, 3) << endl;

    graph.DFS(0);
    cout << endl;
    graph.BFS(0);
    cout << endl;

    return 0;
}