#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class AdjList {
private:
    struct edge {
        int v;
        edge* next;
        edge(int v) : v(v), next(nullptr) {}
    };

    vector<edge*> adj;
public:
    AdjList() = default;

    ~AdjList() {
        for (edge* head : adj) {
            while (head) {
                edge* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    void add_edge(int u, int v) {
        if (has_edge(u, v)) return;

        if (max(u, v) >= adj.size()) {
            adj.resize(max(u, v) + 1, nullptr);
        }
        
        edge* new_edge = new edge(v);
        if (!adj[u]) {
            adj[u] = new_edge;
        } else {
            edge* curr = adj[u];
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = new_edge;
        }
    }

    void remove_edge(int u, int v) {
        if (!has_edge(u, v)) return;

        edge* curr = adj[u];
        edge* prev = nullptr;
        
        while (curr) {
            if (curr->v == v) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    adj[u] = curr->next;
                }
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool has_edge(int u, int v) {
        if (max(u, v) >= adj.size()) return false;

        edge* curr = adj[u];
        while (curr) {
            if (curr->v == v) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void DFS(int start) {
        if (start >= adj.size()) return;

        int n = adj.size();
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(start);

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (visited[u]) continue;
            visited[u] = true;

            cout << u << " ";

            edge* curr = adj[u];
            while (curr) {
                int v = curr->v;
                if (!visited[v]) {
                    st.push(v);
                }
                curr = curr->next;
            }
        }
    }

    void BFS(int start) {
        if (start >= adj.size()) return;

        int n = adj.size();
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            edge* curr = adj[u];
            while (curr) {
                int v = curr->v;
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
                curr = curr->next;
            }
        }
    }
};

int main()
{
    AdjList graph;
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