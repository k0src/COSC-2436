#include <iostream>
#include <list>
#include <unordered_map>

class WeightedGraph {
private:
    struct edge {
        std::string to;
        int weight;
        edge(const std::string& to, int weight) : to(to), weight(weight) {}
    };

    std::unordered_map<std::string, std::list<edge>> adj;

public:
    WeightedGraph() = default;

    void add(const std::string& vertex) {
        if (adj.contains(vertex)) return;

        adj[vertex] = std::list<edge>();
    }

    void remove(const std::string& vertex) {
        if (!adj.contains(vertex)) return;

        adj.erase(vertex);

        for (auto& [v, edges] : adj) {
            edges.remove_if([&vertex](const edge& e) { return e.to == vertex; });
        }
    }

    void add_edge(const std::string& from, const std::string& to, int weight) {
        if (!adj.contains(to) || !adj.contains(from)) return;

        adj[from].push_back({to, weight});
    }

    void remove_edge(const std::string& from, const std::string& to) {
        if (!adj.contains(to) || !adj.contains(from)) return;

        adj[from].remove_if([&to](const edge& e) { return e.to == to; });
    }

    bool query_edge(const std::string& from, const std::string& to) {
        if (!adj.contains(to) || !adj.contains(from)) return false;

        for (const auto& e : adj.at(from)) {
            if (e.to == to) return true;
        }

        return false;
    }

    int edge_weight(const std::string& from, const std::string& to) {
        if (!adj.contains(to) || !adj.contains(from)) return -1;

        for (const auto& e : adj.at(from)) {
            if (e.to == to) return e.weight;
        }

        return -1;
    }

    void print() const {
        for (const auto& [v, edges] : adj) {
            std::cout << v << ": ";
            for (const auto& e : edges) {
                std::cout << "(" << e.to << ", " << e.weight << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    WeightedGraph wg;

    wg.add("A");
    wg.add("B");
    wg.add("C");
    wg.add("D");

    wg.add_edge("A", "B", 1);
    wg.add_edge("A", "C", 2);
    wg.add_edge("B", "D", 3);
    wg.add_edge("C", "D", 4);

    wg.print();

    return 0;
}