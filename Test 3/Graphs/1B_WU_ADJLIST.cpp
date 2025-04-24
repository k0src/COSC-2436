#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class WeightedAdjList {
private:
    struct edge {
        int u, v;
        int weight;
        edge* next;
        edge(int u, int v, int weight) : u(u), v(v), weight(weight), next(nullptr) {}
    };

    vector<edge*> adj;
public:
    ~WeightedAdjList() {
        for (edge* head : adj) {
            while (head) {
                edge* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    void add_edge(int u, int v, int weight) {
        if (has_edge(u, v)) return;

        if (max(u, v) >= adj.size()) {
            adj.resize(max(u, v) + 1, nullptr);
        }

        edge* u_edge = new edge(u, v, weight);
        edge* v_edge = new edge(v, u, weight);

        if (!adj[u]) {
            adj[u] = u_edge;
        } else {
            edge* curr = adj[u];
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = u_edge;
        }

        if (!adj[v]) {
            adj[v] = v_edge;
        } else {
            edge* curr = adj[v];
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = v_edge;
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

        curr = adj[v];
        prev = nullptr;

        while (curr) {
            if (curr->v == u) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    adj[v] = curr->next;
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

    int get_weight(int u, int v) {
        if (max(u, v) >= adj.size()) return -1;

        edge* curr = adj[u]; 
        while (curr) {
            if (curr->v == v) {
                return curr->weight;
            }
            curr = curr->next;
        }
        return -1;
    }

    // Prim's
    vector<vector<int>> MST() {
        vector<bool> visited(adj.size(), false);

        auto compare = [](const edge* a, const edge* b) {
            return a->weight > b->weight;
        };

        priority_queue<edge*, vector<edge*>, decltype(compare)> pq;
        vector<vector<int>> mst;

        visited[0] = true;

        edge* curr = adj[0]; 
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }

        while (!pq.empty()) {
            edge* top = pq.top();
            pq.pop();

            if (visited[top->v]) continue;

            visited[top->v] = true;
            mst.push_back({top->u, top->v, top->weight});

            curr = adj[top->v];
            while (curr) {
                if (!visited[curr->v]) {
                    pq.push(curr);
                }
                curr = curr->next;
            }
        }
        return mst;
    }
};

int main()
{
    WeightedAdjList graph;
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