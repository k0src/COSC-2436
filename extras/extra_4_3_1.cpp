// BFS and DFS one from 4/17/2025

#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

class Graph {
private:    
    std::unordered_map<std::string, std::list<std::string>> adj;

public:
    Graph() = default;

    void add(const std::string& label) {
        if (adj.contains(label)) return;

        adj[label] = std::list<std::string>();
    }

    void add_edge(const std::string& from, const std::string& to) {
        if (!adj.contains(from) || !adj.contains(to)) return;

        adj[from].push_back(to);
    }

    void DFS(const std::string& root) {
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
    g.add("E");
    g.add("F");

    g.add_edge("A", "B");
    g.add_edge("A", "C");
    g.add_edge("B", "D");
    g.add_edge("B", "E");
    g.add_edge("C", "F");

    std::cout << "Graph: \n\n";
    std::cout << "        A\n";
    std::cout << "       / \\\n";
    std::cout << "      B   C\n";
    std::cout << "     / \\   \\\n";
    std::cout << "    D   E   F\n\n";

    std::cout << "DFS:" << std::endl;
    g.DFS("A");
    std::cout << std::endl;

    std::cout << "BFS:" << std::endl;
    g.BFS("A");
    std::cout << std::endl;

    return 0;
}