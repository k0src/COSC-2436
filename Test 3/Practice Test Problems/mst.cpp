#include "help.h"

using namespace std;

using Edge = tuple<string, string, int>; // From, To, Weight
using AdjList = unordered_map<string, list<Edge>>; // Vertex, list of edges

//========= PRIMS ALGORITHM ==========

struct Compare {
    bool operator()(const Edge& a, const Edge& b) {
        return get<2>(a) > get<2>(b);
    }
};

vector<Edge> mstEdges(AdjList& adj) {
    unordered_set<string> visited;
    priority_queue<Edge, vector<Edge>, Compare> pq;
    vector<Edge> res;

    auto v = adj.begin();
    visited.insert(v->first);
    for (auto& e : v->second) {
        pq.push(e);
    }

    while (!pq.empty()) {
        Edge top = pq.top();
        pq.pop();
        string u = get<1>(top);

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
    AdjList adj = 
    {
        {"A", {{"A", "B", 6}, {"A", "E", 5}}},
        {"B", {{"B", "A", 6}, {"B", "C", 4}, {"B", "E", 12}}}, 
        {"C", {{"C", "B", 4}, {"C", "D", 8}, {"C", "E", 10}}}, 
        {"D", {{"D", "C", 8}, {"D", "F", 9}, {"D", "G", 8}, {"D", "H", 5}}}, 
        {"E", {{"E", "A", 5}, {"E", "B", 12}, {"E", "C", 10}, {"E", "F", 10}}},
        {"F", {{"F", "E", 10}, {"F", "D", 9}, {"F", "G", 5}}}, 
        {"G", {{"G", "D", 8}, {"G", "F", 5}, {"G", "H", 6}}}, 
        {"H", {{"H", "D", 5}, {"H", "G", 6}}}
    };

    for (auto& e : mstEdges(adj)) {
        cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
    }

    return 0;
}