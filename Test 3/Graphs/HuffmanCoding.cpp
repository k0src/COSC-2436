#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

struct HuffmanNode {
    char c;
    int freq;
    HuffmanNode* left; 
    HuffmanNode* right;
    HuffmanNode(char c, int freq) : c(c), freq(freq), left(nullptr), right(nullptr) {}
};

std::string huffmanDecoding(const std::string& encoded, HuffmanNode* root) {
    std::string decoded;
    HuffmanNode* current = root;

    for (char bit : encoded) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decoded += current->c;
            current = root;
        }
    }
    return decoded;
}

void buildCodeMap(HuffmanNode* node, const std::string& path, std::unordered_map<char, std::string>& codeMap) {
    if (!node) return;

    if (!node->left && !node->right) {
        codeMap[node->c] = path;
        return;
    }

    buildCodeMap(node->left, path + "0", codeMap);
    buildCodeMap(node->right, path + "1", codeMap);
}

std::unordered_map<char, std::string> getCodeMap(HuffmanNode* root) {
    std::unordered_map<char, std::string> codeMap;
    buildCodeMap(root, "", codeMap);
    return codeMap;
}

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

HuffmanNode* huffmanEncoding(const std::string& data) {
    std::vector<int> freq(256, 0);

    for (char c : data) {
        freq[c]++;
    }

    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            pq.push(new HuffmanNode(i, freq[i]));
        }
    }    

    while (pq.size() != 1) {
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    HuffmanNode* root = pq.top();
    return root;
}

int main()
{
    std::string data = "lossless";
    HuffmanNode* tree = huffmanEncoding(data);

    std::cout << "Data: "<< data << std::endl;

    std::cout << "Huffman Codes:" << std::endl;
    std::unordered_map<char, std::string> codeMap = getCodeMap(tree);
    for (const auto& pair : codeMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Decoded Data:" << std::endl;
    std::string encoded;
    for (char c : data) {
        encoded += codeMap[c];
    }
    std::cout << huffmanDecoding(encoded, tree);

    return 0;
}