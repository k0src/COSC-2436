#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iomanip>

class GameBoard {
public:
    GameBoard() {
        Node* head = new Node(1);
        start = head;
        end = head;
        nodes.push_back(head);

        for (int i = 1; i < board_size; i++) {
            Node* node = new Node(i + 1);
            end->next = node;
            node->prev = end;
            end = node;

            nodes.push_back(node);
        }

        // add jump locations
        Node* current = start->next;
        
        while (current) {
            int random_num = rand() % 100;
            if (random_num < 15) {
                generate_jump_location(current);
            }
            current = current->next;
        }

        printBoard();
    }

    void simulateGame(int n_players) {
        if (n_players < 1) throw std::invalid_argument("Too little players.");

        bool winner = false;
        
        // create the players
        for (int i = 0; i < n_players; i++) {
            players.insert(std::make_pair(i + 1, 1)); // player number and initial pos
        }

        while (!winner) {
            printBoard();
        }
    }

    void test() {
        Node* current = start;
        while (current) {
            std::cout << "pos: " << current->position << std::endl;
            std::cout << "jump location: " << current->jump_location << std::endl;
            current = current->next;
        }
    }
private:
    struct Node {
        Node(int position) : position(position), jump_location(0), next(nullptr), prev(nullptr){}
        int position;
        int jump_location;
        Node* next;
        Node* prev;
    };
    
    void generate_jump_location(Node*& node) {
        if (node->jump_location != 0) return;

        int jump_location = 0;

        do {
            // decide if jump location is ladder or snake weighted based on the value of the node's position
            bool is_ladder = ((rand() % 100) < (100 - (node->position * 100 / board_size)));

            if (is_ladder) {
                jump_location = node->position + (rand() % (board_size - node->position));
            } else {
                jump_location = 1 + (rand() % (node->position - 1));
            }

        } while (nodes[jump_location - 1]->jump_location != 0 || jump_location == node->position);

        node->jump_location = jump_location;
    }

    int dice() const {
        return (rand() % 6) + 1;
    }

    void printBoard() {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int num = board_size - (row * cols + col);
                if (num < 10) {
                    std::cout << "[  " << num << "]";
                } else if (num < 100) {
                    std::cout << "[ " << num << "]";
                } else {
                    std::cout << "[" << num << "]";
                }
            }
            std::cout << std::endl;
        }
    }

    Node* start;
    Node* end;

    std::vector<Node*> nodes;
    std::unordered_map<int, int> players;

    const int board_size = 100;
    const int cols = 10;
    const int rows = 10;
};

int main()
{
    GameBoard gb;
    // gb.simulateGame(3);

    return 0;
}