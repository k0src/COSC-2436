#include <iostream>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

using edge = pair<string, string>;

class AdjList {
private:
    unordered_map<string, list<edge>> adj;
public:
    AdjList() = default;

    void insert(const string& u) {
        if (adj.contains(u)) return;

        adj[u] = list<edge>();
    }

    void remove(const string& u) {
        if (!adj.contains(u)) return;

        adj.erase(u);

        for (auto& [_, edges] : adj) {
            edges.remove_if([&](const edge& e) { return e.first == u || e.second == u; });
        }
    }

    void add_edge(const string& u, const string& v) {
        if (!adj.contains(u) || !adj.contains(v)) return;

        for (const auto& [from, to] : adj.at(u)) {
            if (to == v) return;
        }

        adj.at(u).push_back({u, v});
        adj.at(v).push_back({v, u});
    }

    void remove_edge(const string& u, const string& v) {
        if (!adj.contains(u) || !adj.contains(v)) return;

        adj.at(u).remove_if([&](const edge& e) { return e.first == u && e.second == v; });
        adj.at(v).remove_if([&](const edge& e) { return e.first == v && e.second == u; });
    }

    bool has_edge(const string& u, const string& v) {
        if (!adj.contains(u) || !adj.contains(v)) return false;

        for (const auto& [from, to] : adj.at(u)) {
            if (to == v) return true;
        }

        return false;
    }

    void DFS(const string& root) {
        unordered_set<string> visited;
        stack<string> st;
        st.push(root);

        while (!st.empty()) {
            string u = st.top();
            st.pop();

            if (visited.contains(u)) continue;

            cout << u << " ";

            visited.insert(u);

            for (const auto& [_, v] : adj.at(u)) {
                if (!visited.contains(v)) {
                    st.push(v);
                }
            }
        }
    }

    void BFS(const string& root) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(root);
        visited.insert(root);

        while (!q.empty()) {
            string u = q.front();
            q.pop();

            cout << u << " ";

            for (const auto& [_, v] : adj.at(u)) {
                if (!visited.contains(v)) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }
};

int main() 
{
    AdjList g;
    g.insert("A");
    g.insert("B");
    g.insert("C");
    g.insert("D");
    g.insert("E");
    g.insert("F");

    g.add_edge("A", "B");
    g.add_edge("A", "C");
    g.add_edge("A", "E");
    g.add_edge("B", "C");
    g.add_edge("B", "D");
    g.add_edge("C", "D");
    g.add_edge("D", "E");
    g.add_edge("E", "F");

    cout << g.has_edge("A", "B") << endl;
    cout << g.has_edge("F", "A") << endl;

    g.DFS("A");
    cout << endl;
    g.BFS("A");

    return 0;
}