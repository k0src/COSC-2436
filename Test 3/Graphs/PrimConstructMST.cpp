#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

// Prim's algorithm to compute MST
// Returns a list of edges in the MST using lazy evaluation

using Edge = std::tuple<std::string, std::string, int>;  // from, to, weight
using AdjList = std::unordered_map<std::string, std::list<Edge>>; // Vertex, list of edges

struct Compare {
    bool operator()(const Edge& a, const Edge& b) {
        return std::get<2>(a) > std::get<2>(b);
    }
};

std::vector<Edge> MST(AdjList& adj) {
    std::unordered_set<std::string> visited;
    std::priority_queue<Edge, std::vector<Edge>, Compare> pq;
    std::vector<Edge> res;

    auto v = adj.begin();
    visited.insert(v->first);
    for (auto& e : v->second) {
        pq.push(e);
    }

    while (!pq.empty()) {
        Edge top = pq.top();
        std::string u = std::get<1>(top);
        pq.pop();

        if (visited.contains(u)) {
            continue;
        }

        res.push_back(top);
        visited.insert(u);

        for (auto& e : adj.at(u)) {
            pq.push(e);
        }
    }

    return res;
}

int main() 
{
    AdjList adj;
    adj["A"] = { {"A", "B", 10}, {"A", "C", 1}, {"A", "D", 4} };
    adj["B"] = { {"B", "A", 10}, {"B", "E", 0}, {"B", "C", 3} };
    adj["C"] = { {"C", "A", 1}, {"C", "F", 8}, {"C", "B", 3}, {"C", "D", 2} };
    adj["D"] = { {"D", "A", 4}, {"D", "F", 2}, {"D", "G", 7}, {"D", "C", 2} };
    adj["E"] = { {"E", "B", 0}, {"E", "F", 1}, {"E", "H", 8} };
    adj["F"] = { {"F", "E", 1}, {"F", "C", 8}, {"F", "H", 9}, {"F", "G", 6}, {"F", "D", 2} };
    adj["G"] = { {"G", "D", 7}, {"G", "F", 6}, {"G", "H", 12} };
    adj["H"] = { {"H", "E", 8}, {"H", "F", 9}, {"H", "G", 12} };

    std::vector<Edge> edges = MST(adj);
    int totalWeight = 0;

    std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : edges) {
        std::cout << std::get<0>(edge) << " - " << std::get<1>(edge) << " : " << std::get<2>(edge) << std::endl;
        totalWeight += std::get<2>(edge);
    }

    std::cout << "Total weight of MST: " << totalWeight << std::endl;

    return 0;
}