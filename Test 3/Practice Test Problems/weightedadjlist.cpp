#include <iostream>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

using edge = tuple<string, string, int>;

class WeightedGraph {
private:
    unordered_map<string, list<edge>> adj;
public:
    WeightedGraph() = default;

    void insert(const string& u) {
        if (adj.contains(u)) return;

        adj[u] = list<edge>();
    }

    void remove(const string& u) {
        if (!adj.contains(u)) return;

        adj.erase(u);

        for (auto& [_, edges] : adj) {
            edges.remove_if([&](const edge& e) { return get<0>(e) == u || get<1>(e) == u; });
        }
    }

    void add_edge(const string& u, const string& v, int weight) {
        if (!adj.contains(u) || !adj.contains(v)) return;

        for (const auto& [from, to, weight] : adj.at(u)) {
            if (to == v) return;
        }

        adj.at(u).push_back({u, v, weight});
        adj.at(v).push_back({v, u, weight});
    }

    void remove_edge(const string& u, const string& v) {
        if (!adj.contains(u) || !adj.contains(v)) return;

        adj.at(u).remove_if([&](const edge& e) { return get<0>(e) == u && get<1>(e) == v; });
        adj.at(v).remove_if([&](const edge& e) { return get<0>(e) == v && get<1>(e) == u; });
    }

    bool edge_exists(const string& u, const string& v) {
        if (!adj.contains(u) || !adj.contains(v)) return false;

        for (auto& [from, to, weight] : adj.at(u)) {
            if (to == v) return true;
        }

        return false;
    }

    int edge_weight(const string& u, const string& v) {
        if (!adj.contains(u) || !adj.contains(v)) return -1;

        for (auto& [from, to, weight] : adj.at(u)) {
            if (to == v) return weight;
        }

        return -1;
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

            for (const auto& [from, to, weight] : adj.at(u)) {
                if (!visited.contains(to)) {
                    st.push(to);
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

            for (const auto& [from, to, weight] : adj.at(u)) {
                if (!visited.contains(to)) {
                    visited.insert(to);
                    q.push(to);
                }
            }
        }
    }

    void dijkstra(const string& start) {
        unordered_map<string, int> distances;
        unordered_set<string> visited;

        for (const auto& [v, _] : adj) {
            distances[v] = INT_MAX;
        }

        using p = pair<int, string>; // Distance, Vertex
        priority_queue<p, vector<p>, greater<p>> pq;

        distances[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int dist = pq.top().first;
            string u = pq.top().second;
            pq.pop();

            if (visited.contains(u)) continue;

            visited.insert(u);

            for (const auto& [from, to, weight] : adj.at(u)) {
                if (!visited.contains(to) && dist + weight < distances[to]) {
                    distances[to] = dist + weight;
                    pq.push({distances[to], to});
                }
            }
        }

        for (const auto& [v, d] : distances) {
            cout << v << ": " << d << endl;
        }
    }

    struct compare {
        bool operator()(const edge& a, const edge& b) const {
            return get<2>(a) > get<2>(b);
        }
    };

    void MSTPrim() {
        unordered_set<string> visited;
        priority_queue<edge, vector<edge>, compare> pq;
        vector<edge> res;

        auto v = adj.begin();
        visited.insert(v->first);
        for (auto& e : v->second) {
            pq.push(e);
        }

        while (!pq.empty()) {
            edge top = pq.top();
            string u = get<1>(top);
            pq.pop();

            if (visited.contains(u)) continue;

            res.push_back(top);
            visited.insert(u);

            for (auto& e : adj.at(u)) {
                if (!visited.contains(get<1>(e))) {
                    pq.push(e);
                }
            }
        }

        for (const auto& [from, to, weight] : res) {
            cout << from << " - " << to << ": " << weight << endl;
        }
    }
};

int main()
{
    WeightedGraph g;

    g.insert("A");
    g.insert("B");
    g.insert("C");
    g.insert("D");
    g.insert("E");
    g.insert("F");

    g.add_edge("A", "B", 4);
    g.add_edge("A", "C", 4);
    g.add_edge("B", "C", 2);
    g.add_edge("B", "E", 1);
    g.add_edge("C", "D", 1);
    g.add_edge("D", "F", 2);
    g.add_edge("E", "F", 4);

    cout << g.edge_exists("A", "B") << endl;
    cout << g.edge_exists("A", "F") << endl;
    cout << g.edge_weight("A", "B") << endl;

    g.DFS("A");
    cout << endl;
    g.BFS("A");
    cout << endl;

    g.dijkstra("A");
    cout << endl;

    g.MSTPrim();
    cout << endl;

    return 0;
}