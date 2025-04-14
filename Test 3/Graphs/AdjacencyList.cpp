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
};

int main()
{
    Graph g;
    g.add("A");
    g.add("B");
    g.add("C");
    g.add("D");

    g.add_edge("A", "B");
    g.add_edge("A", "C");
    g.add_edge("B", "D");
    g.add_edge("C", "D");

    g.print();

    return 0;
}