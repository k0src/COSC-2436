#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <limits>

using Edge = std::pair<std::string, int>; // (neighbor, weight)
using graph = std::unordered_map<std::string, std::vector<Edge>>;

std::unordered_map<std::string, int> dijkstra(const graph& g, const std::string& start) {
    std::unordered_map<std::string, int> distances;
    std::unordered_set<std::string> visited;

    for (const auto& [v, _] : g) {
        distances[v] = std::numeric_limits<int>::max();
    }

    using pair = std::pair<int, std::string>; // (distance, vertex)
    std::priority_queue<pair, std::vector<pair>, std::greater<pair>> pq;

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        std::string u = pq.top().second;
        pq.pop();

        if (visited.contains(u)) {
            continue;
        }

        visited.insert(u);

        for (const auto& [v, weight] : g.at(u)) {
            if (!visited.contains(v) && dist + weight < distances[v]) {
                distances[v] = dist + weight;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

int main()
{
    graph g = {
        {"A", {{"B", 10}, {"C", 3}}},
        {"B", {{"D", 2}, {"C", 1}}},
        {"C", {{"D", 8}, {"E", 2}, {"B", 4}}},
        {"D", {{"E", 7}}},
        {"E", {{"D", 9}}} 
    };

    std::string start = "A";
    auto distances = dijkstra(g, start);

    std::cout << "Shortest distances from " << start << ":\n";
    for (const auto& [vertex, distance] : distances) {
        if (distance == std::numeric_limits<int>::max()) {
            std::cout << vertex << ": unreachable\n";
        } else {
            std::cout << vertex << ": " << distance << "\n";
        }
    }

    return 0;
}