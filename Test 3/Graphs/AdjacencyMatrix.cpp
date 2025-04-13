#include <iostream>
#include <unordered_map>
#include <vector>

class Graph {
private:
    std::unordered_map<std::string, int> label_to_index;
    std::vector<std::string> index_to_label;
    std::vector<std::vector<bool>> matrix;

public:
    Graph() = default;

    void add(const std::string& label) {
        if (label_to_index.contains(label)) return;

        int index = index_to_label.size();
        label_to_index[label] = index;
        index_to_label.push_back(label);

        for (auto& row : matrix) {
            row.push_back(false);
        }
        matrix.push_back(std::vector<bool>(index + 1, false));
    }

    void remove(const std::string& label) {
        if (!label_to_index.contains(label)) return;

        int index = label_to_index[label];

        label_to_index.erase(label);
        index_to_label.erase(index_to_label.begin() + index);
        matrix.erase(matrix.begin() + index);
        for (auto& row : matrix) {
            row.erase(row.begin() + index);
        }

        label_to_index.clear();
        for (int i = 0; i < index_to_label.size(); ++i) {
            label_to_index[index_to_label[i]] = i;
        }
    }

    void add_edge(const std::string& from, const std::string& to) {
        if (!label_to_index.contains(from) || !label_to_index.contains(to)) return;

        int i = label_to_index[from];
        int j = label_to_index[to];
        matrix[i][j] = true;
    }

    void remove_edge(const std::string& from, const std::string& to) {
        if (!label_to_index.contains(from) || !label_to_index.contains(to)) return;

        int i = label_to_index[from];
        int j = label_to_index[to];
        matrix[i][j] = false;
    }

    bool edge_exists(const std::string& from, const std::string& to) {
        if (!label_to_index.contains(from) || !label_to_index.contains(to)) return false;

        int i = label_to_index[from];
        int j = label_to_index[to];
        return matrix[i][j];
    }

    void print() const {
        int n = index_to_label.size();
        std::cout << "  ";
        for (const auto& label : index_to_label) {
            std::cout << label << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; ++i) {
            std::cout << index_to_label[i] << " ";
            for (int j = 0; j < n; ++j) {
                std::cout << (matrix[i][j] ? "1" : "0") << " ";
            }
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