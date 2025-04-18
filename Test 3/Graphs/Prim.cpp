#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

struct Compare {
    bool operator()(const std::pair<std::string, int>& a,
                    const std::pair<std::string, int>& b) {
        return a.second > b.second;
    }
};

int mstCost(std::unordered_map<std::string, std::list<std::pair<std::string, int>>>& adj) {
    std::unordered_set<std::string> visited;
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> pq;
    int res = 0;

    auto v = adj.begin();
    visited.insert(v->first);
    for (auto& e : v->second) {
        pq.push(e);
    }

    while (!pq.empty()) {
        std::string u = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if (visited.contains(u)) {
            continue;
        }

        res += weight;
        visited.insert(u);

        for (auto& e : adj.at(u)) {
            pq.push(e);
        }
    }

    return res;
}

int main() 
{
    std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adj;
    adj["A"] = {{"B", 10}, {"C", 1}, {"D", 4}};
    adj["B"] = {{"A", 10}, {"E", 0}, {"C", 3}};
    adj["C"] = {{"A", 1}, {"F", 8}, {"B", 3}, {"D", 2}};
    adj["D"] = {{"A", 4}, {"F", 2}, {"G", 7}, {"C", 2}};
    adj["E"] = {{"B", 0}, {"F", 1}, {"H", 8}};
    adj["F"] = {{"E", 1}, {"C", 8}, {"H", 9}, {"G", 6}, {"D", 2}};
    adj["G"] = {{"D", 7}, {"F", 6}, {"H", 12}};
    adj["H"] = {{"E", 8}, {"F", 9}, {"G", 12}};

    std::cout << "Minimum Spanning Tree Cost: " << mstCost(adj) << std::endl;

    return 0;
}