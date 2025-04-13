#include <iostream>
#include <list>
#include <unordered_map>

class Graph {
private:
    std::unordered_map<std::string, std::list<std::string>> adj;
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
    std::cout << std::endl;

    g.remove_edge("A", "C");

    g.print();
    std::cout << std::endl;

    g.remove("B");

    g.print();
    std::cout << std::endl;

    return 0;
}