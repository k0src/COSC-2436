#include <vector>
#include <iostream>
#include <unordered_map>

class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

int main()
{
    // 7 elements:
    std::vector<std::string> elements = {"B", "A", "D", "F", "E", "G", "C"};
    // Create bijection, each element is associated with an integer 0-6
    std::unordered_map<std::string, int> bijection;
    for (int i = 0; i < elements.size(); ++i) {
        bijection[elements[i]] = i;
    }
    // Create DSU
    DSU dsu(7);
    // Unite A and G
    dsu.unite(1, 5); // A -> 1, G -> 5
    // Unite B and E
    dsu.unite(0, 4); // B -> 0, E -> 4
    // Unite D and F
    dsu.unite(2, 3); // D -> 2, F -> 3
    // Unite F and C
    dsu.unite(3, 6); // F -> 3, C -> 6
    // Unite G and D
    dsu.unite(5, 2); // G -> 5, D -> 2
    // There are now two sets: {B, E} and {A, C, D, F, G}
    // Find the Root of each element
    for (int i = 0; i < elements.size(); ++i) {
        int root = dsu.find(i);
        std::cout << "Element: " << elements[i] << ", Root: " << elements[root] << std::endl;
    }

    return 0;
}