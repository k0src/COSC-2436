#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void dfs(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<bool> visited(n, false);
    std::stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        
        if (visited[u]) continue;

        visited[u] = true;
        std::cout << u << " ";

        for (int v = n - 1; v >= 0; v--) {
            if (graph[u][v] == 1 && !visited[v]) {
                st.push(v);
            }
        }
    }
}

void bfs(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    dfs(graph, 0); // Starting DFS from vertex 0
    std::cout << std::endl;
    bfs(graph, 0); // Starting BFS from vertex 0 

    return 0;
}