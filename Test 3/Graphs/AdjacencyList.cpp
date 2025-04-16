#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

class Graph {
private:
    std::unordered_map<std::string, std::list<std::string>> adj;

    void DFS(const std::string& root, std::unordered_set<std::string>& visited) {
        std::cout << root << " ";
        visited.insert(root);

        for (auto& neighbor : adj.at(root)) {
            if (!visited.contains(neighbor)) {
                DFS(neighbor, visited);
            }
        }
    }

    void topologicalSort(const std::string& vertex, std::unordered_set<std::string>& visited, std::stack<std::string>& st) {
        if (visited.contains(vertex)) return;

        visited.insert(vertex);

        for (const auto& neighbor : adj.at(vertex)) {
            topologicalSort(neighbor, visited, st);
        }

        st.push(vertex);
    }

    bool hasCycle(const std::string& vertex, std::unordered_set<std::string>& visited, std::unordered_set<std::string>& rec_stack) {
        if (rec_stack.contains(vertex)) return true;
        if (visited.contains(vertex)) return false;

        visited.insert(vertex);
        rec_stack.insert(vertex);

        for (const auto& neighbor : adj.at(vertex)) {
            if (hasCycle(neighbor, visited, rec_stack)) {
                return true;
            }
        }

        rec_stack.erase(vertex);
        return false;
    }

public:
    Graph() = default;

    void add(const std::string& label) {
        if (adj.contains(label)) return;

        adj[label] = std::list<std::string>();
    }

    void remove(const std::string& label) {
        if (!adj.contains(label)) return;

        adj.erase(label);
        
        for (auto& [v, neighbors] : adj) {
            neighbors.remove(label);
        }
    }

    void add_edge(const std::string& from, const std::string& to) {
        if (!adj.contains(from) || !adj.contains(to)) return;

        adj[from].push_back(to);
    }

    void remove_edge(const std::string& from, const std::string& to) {
        if (!adj.contains(from) || !adj.contains(to)) return;

        adj[from].remove(to);
    }

    bool edge_exists(const std::string& from, const std::string& to) {
        if (!adj.contains(from)) return false;

        for (const auto& neighbor : adj.at(from)) {
            if (neighbor == to) return true;
        }

        return false;
    }

    void print() const {
        for (const auto& [v, neighbors] : adj) {
            std::cout << v << ": ";
            for (const auto& to : neighbors)
                std::cout << to << " ";
            std::cout << std::endl;
        }
    }

    void DFS(const std::string& root) {
        if (!adj.contains(root)) return;
         
        std::unordered_set<std::string> visited;
        DFS(root, visited);
    }

    void DFSIterative(const std::string& root) {
        if (!adj.contains(root)) return;

        std::unordered_set<std::string> visited;
        std::stack<std::string> stack;
        stack.push(root);

        while (!stack.empty()) {
            std::string node = stack.top();
            stack.pop();

            if (visited.contains(node)) continue;

            std::cout << node << " ";
            visited.insert(node);

            for (const auto& neighbor : adj.at(node)) {
                if (!visited.contains(neighbor)) {
                    stack.push(neighbor);
                }
            }
        }
    }

    void BFS(const std::string& root) {
        if (!adj.contains(root)) return;

        std::unordered_set<std::string> visited;
        std::queue<std::string> queue;
        queue.push(root);
        visited.insert(root);

        while (!queue.empty()) {
            std::string node = queue.front();
            queue.pop();

            std::cout << node << " ";

            for (const auto& neighbor : adj.at(node)) {
                if (!visited.contains(neighbor)) {
                    queue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }

    std::vector<std::string> topologicalSort() {
        std::unordered_set<std::string> visited;
        std::stack <std::string> st;

        for (const auto& [v, _] : adj) {
            if (!visited.contains(v)) {
                topologicalSort(v, visited, st);
            }
        }

        std::vector<std::string> sorted;

        while (!st.empty()) {
            sorted.push_back(st.top());
            st.pop();
        }

        return sorted;
    }

    std::vector<std::string> topologicalSortKahn() {
        std::unordered_map<std::string, int> in_degree;
        std::queue<std::string> queue;
        std::vector<std::string> sorted;

        for (const auto& [v, neighbors] : adj) {
            in_degree[v] = 0;
        }

        for (const auto& [v, neighbors] : adj) {
            for (const auto& neighbor : neighbors) {
                in_degree[neighbor]++;
            }
        }

        for (const auto& [v, degree] : in_degree) {
            if (degree == 0) {
                queue.push(v);
            }
        }

        while (!queue.empty()) {
            std::string v = queue.front();
            queue.pop();
            sorted.push_back(v);

            for (const auto& neighbor : adj.at(v)) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }

        return sorted;
    }

    bool hasCycle() {
        std::unordered_set<std::string> visited;
        std::unordered_set<std::string> rec_stack;

        for (const auto& [v, _] : adj) {
            if (!visited.contains(v) && hasCycle(v, visited, rec_stack)) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Graph g;
    g.add("A");
    g.add("B");
    g.add("C");
    g.add("D");
    g.add("E");
    g.add("F");

    g.add_edge("A", "D");
    g.add_edge("A", "C");
    g.add_edge("B", "C");
    g.add_edge("B", "E");
    g.add_edge("D", "F");
    g.add_edge("F", "E");

    std::cout << g.hasCycle();

    return 0;
}