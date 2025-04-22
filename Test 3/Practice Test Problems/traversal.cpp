#include "help.h"

using namespace std;

// DFS

void dfsList(unordered_map<string, list<string>>& adjList, const string& root) {
    unordered_set<string> visited;
    stack<string> st;
    st.push(root);

    while (!st.empty()) {
        string u = st.top();
        st.pop();

        if (visited.contains(u)) continue;

        cout << u << " ";
        visited.insert(u);

        for (const auto& v : adjList.at(u)) {
            if (!visited.contains(v)) {
                st.push(v);
            }
        }
    }
}

void dfsMatrix(const vector<vector<int>>& graph, int root) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(root);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (visited[u]) continue;

        visited[u] = true;
        cout << u << " ";

        for (int v = n - 1; v >= 0; v--) {
            if (graph[u][v] == 1 && !visited[v]) {
                st.push(v);
            }
        }
    }
}

// BFS

void bfsList(unordered_map<string, list<string>>& adjList, const string& root) {
    unordered_set<string> visited;
    queue<string> q;
    q.push(root);
    visited.insert(root);

    while (!q.empty()) {
        string u = q.front();
        q.pop();

        cout << u << " ";

        for (const auto& v : adjList.at(u)) {
            if (!visited.contains(v)) {
                q.push(v);
                visited.insert(v);
            }
        }
    }
}

void bfsMatrix(vector<vector<int>>& graph, int root) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[root] = true;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

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
    unordered_map<string, list<string>> adjList = {
        {"A", {"B", "C"}},
        {"B", {"A", "D", "E"}},
        {"C", {"A", "F"}},
        {"D", {"B", "F"}},
        {"E", {"B", "F"}},
        {"F", {"C", "E", "D"}}
    };

    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0}
    };

    cout << "DFS\n";
    dfsList(adjList, "A");
    cout << endl;
    dfsMatrix(adjMatrix, 0);
    cout << endl;
    cout << "BFS\n";
    bfsList(adjList, "A");
    cout << endl;
    bfsMatrix(adjMatrix, 0);


    return 0;
}