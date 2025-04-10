#include <iostream>
#include <list>
#include <vector>

template <typename T>
class Graph {
private:
    T impl;
public:
    Graph(int n_vertices) : impl(n_vertices) {}

    void addEdge(int i, int j) {
        impl.addEdge(i, j);
    }

    void removeEdge(int i, int j) {
        impl.removeEdge(i, j);
    }

    bool hasEdge(int i, int j) {
        return impl.hasEdge(i, j);
    }

    void printEdges() const {
        impl.printEdges();
    }

    bool empty() {
        return impl.empty();
    }
};

class AdjacencyMatrix {
private:
    std::vector<std::vector<int> > matrix;
    int n_vertices;
public:
    AdjacencyMatrix(int n_vertices) : n_vertices(n_vertices) {
        matrix.resize(n_vertices, std::vector<int>(n_vertices, 0));
    }

    void addEdge(int i, int j) {
        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    void removeEdge(int i, int j) {
        matrix[i][j] = 0;
        matrix[j][i] = 0;
    }

    bool hasEdge(int i, int j) {
        return matrix[i][j] == 1;
    }

    void printEdges() const {
        for (int i = 0; i < n_vertices; i++) {
            for (int j = i + 1; j < n_vertices; j++) {
                if (matrix[i][j] == 1) {
                    std::cout << "{" << i << ", " << j << "}" << std::endl;
                }
            }
        }
    }

    bool empty() {
        for (int i = 0; i < n_vertices; i++) {
            for (int j = 0; j < n_vertices; j++) {
                if (matrix[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

class AdjacencyList {
private:
    std::vector<std::list<int> > adj;
    int n_vertices;
public:
    AdjacencyList(int n_vertices) : n_vertices(n_vertices) {
        adj.resize(n_vertices);
    }

    void addEdge(int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    void removeEdge(int i, int j) {
        adj[i].remove(j);
        adj[j].remove(i);
    }

    bool hasEdge(int i, int j) {
        for (int vertex : adj[i]) {
            if (vertex == j) {
                return true;
            }
        }
        return false;
    }

    void printEdges() const {
        for (int i = 0; i < n_vertices; i++) {
            for (int vertex : adj[i]) {
                if (vertex > i) {
                    std::cout << "{" << i << ", " << vertex << "}" << std::endl;
                }
            }
        }
    }

    bool empty() {
        for (int i = 0; i < n_vertices; i++) {
            if (!adj[i].empty()) {
                return false;
            }
        }
        return true;
    }
};

template <typename T>
void graphMenu(T& graph) {
    while (true) {
        std::cout << "Graph Menu" << std::endl;
        std::cout << "1. Add Edge" << std::endl;
        std::cout << "2. Remove Edge" << std::endl;
        std::cout << "3. Check Edge" << std::endl;
        std::cout << "4. Print Edges" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int i, j;
            std::cout << "Enter edge vertices (i, j): ";
            std::cin >> i >> j;
            graph.addEdge(i, j);
        } else if (choice == 2) {
            int i, j;
            std::cout << "Enter edge vertices (i, j): ";
            std::cin >> i >> j;
            graph.removeEdge(i, j);
        } else if (choice == 3) {
            int i, j;
            std::cout << "Enter edge vertices (i, j): ";
            std::cin >> i >> j;
            if (graph.hasEdge(i, j)) {
                std::cout << "Edge {" << i << ", " << j << "} exists" << std::endl;
            } else {
                std::cout << "Edge {" << i << ", " << j << "} does not exist" << std::endl;
            }
        } else if (choice == 4) {
            graph.printEdges();
        } else {
            break;
        }
    }
}

int main()
{
    std::cout << "Enter graph type followed by number of vertices" << std::endl;
    std::cout << "1. Adjacency Matrix" << std::endl;
    std::cout << "2. Adjacency List" << std::endl;

    int graphType, n_vertices;
    std::cin >> graphType >> n_vertices;

    if (graphType == 1) {
        Graph<AdjacencyMatrix> graph(n_vertices);
        graphMenu(graph);
        
    } else if (graphType == 2) {
        Graph<AdjacencyList> graph(n_vertices);
        graphMenu(graph);
    } else {
        std::cerr << "Invalid graph type" << std::endl;
        return 1;
    }

    return 0;
}