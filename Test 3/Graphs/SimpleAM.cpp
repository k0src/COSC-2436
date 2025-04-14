#include <iostream>
#include <vector>

class AdjacencyMatrix {
private:
    std::vector<std::vector<int> > matrix;
    int n_vertices;
public:
    AdjacencyMatrix(int n_vertices) : n_vertices(n_vertices) {
        matrix.resize(n_vertices, std::vector<int>(n_vertices, 0));
    }

    void addEdge(int i, int j) {
        if (i < 0 || i >= n_vertices || j < 0 || j >= n_vertices) return;

        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    void removeEdge(int i, int j) {
        if (i < 0 || i >= n_vertices || j < 0 || j >= n_vertices) return;

        matrix[i][j] = 0;
        matrix[j][i] = 0;
    }

    bool hasEdge(int i, int j) {
        if (i < 0 || i >= n_vertices || j < 0 || j >= n_vertices) return;
        
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