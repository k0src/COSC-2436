#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <chrono>
#include <thread>
#include <atomic>
#include <limits>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

std::atomic<bool> quit(false);

#ifndef _WIN32
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
}

int getch() {
    int ch;
    ch = getchar();
    return ch;
}
#endif

void checkKeyPress() {
    while (!quit) {
        #ifdef _WIN32
        if (_kbhit()) {
            char c = _getch();
            if (c == 'q') {
                quit = true;
            }
        }
        #else
        // Unix-like systems
        if (kbhit()) {
            char c = getch();
            if (c == 'q') {
                quit = true;
            }
        }
        #endif
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

class GameBoard {
public:
    GameBoard() {
        Node* head = new Node(1);
        start = head;
        end = head;

        for (int i = 1; i < board_size; i++) {
            Node* node = new Node(i + 1);
            end->next = node;
            node->prev = end;
            end = node;
        }

        Node* current = start->next;
        
        while (current) {
            int random_num = rand() % 100;
            if (random_num < 15) {
                generate_jump_location(current);
            }
            current = current->next;
        }
    }

    void simulateGame() {
        int n_players;
        int speed;
    
        std::cout << "Enter number of players (at least 1): ";
        std::cin >> n_players;
        std::cout << "Enter game speed: ";
        std::cin >> speed;
    
        if (n_players < 1) throw std::invalid_argument("Too little players.");
    
        std::cout << "Simulating game with " << n_players << " players. Press 'q' to quit." << std::endl;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::thread keyThread(checkKeyPress);
        
        // create the players
        for (int i = 0; i < n_players; i++) {
            Player* player = new Player(i + 1, 1);
            players.push_back(player);
        }
    
        while (!quit) {
            std::cout << "Rolling dice..." << std::endl;
            
            for (auto& player : players) {
                if (quit) {
                    std::cout << "Quitting..." << std::endl;
                    break;
                }
                
                int roll = dice();
                std::cout << "Player: " << player->player_number << " rolled: " << roll << std::endl;
    
                // move player
                int new_position = player->position + roll;
    
                if (jump_locations.count(new_position) > 0) {
                    if (new_position < jump_locations[new_position]) {
                        std::cout << "Player: " << player->player_number << " climbs a ladder to " << jump_locations[new_position] << "!" << std::endl;
                    } else {
                        std::cout << "Player: " << player->player_number << " slides down to " << jump_locations[new_position] << "!" << std::endl;
                    }
                    player->position = jump_locations[new_position];
                } else if (new_position == board_size) {
                    std::cout << "Player: " << player->player_number << " wins!" << std::endl;
                    quit = true;
                    printBoard();
                    break;
                } else if (new_position < board_size) {
                    std::cout << "Player: " << player->player_number << " moves to " << new_position << "!" << std::endl;
                    player->position = new_position;
                } else {
                    std::cout << "Player: " << player->player_number << " stays at " << player->position << "!" << std::endl;
                }
    
                std::this_thread::sleep_for(std::chrono::milliseconds(1000 / speed));
                printBoard();
            }
        }
        
        keyThread.join();
    }
private:
    struct Node {
        Node(int position) : position(position), jump_location(0), next(nullptr), prev(nullptr){}
        int position;
        int jump_location;
        Node* next;
        Node* prev;
    };

    struct Player {
        Player(int player_number, int position) : player_number(player_number), position(position) {}
        int player_number;
        int position;
    };
    
    void generate_jump_location(Node*& node) {
        if (node->jump_location != 0) return;

        int jump_location = 0;

        do {
            // decide if jump location is ladder or snake weighted based on the value of the node's position
            bool is_ladder = ((rand() % 100) < (100 - (node->position * 100 / board_size)));
        
            if (is_ladder) {
                jump_location = node->position + (rand() % (board_size - node->position) + 1);
            } else {
                jump_location = 1 + (rand() % (node->position - 1));
            }
        
        } while (jump_locations.count(node->position) > 0 || jump_location == node->position);
        

        node->jump_location = jump_location;
        jump_locations.insert(std::make_pair(node->position, node->jump_location));
    }

    int dice() const {
        return (rand() % 6) + 1;
    }

    void printBoard() {
        int count = 0;

        for (int i = board_size; i > 0; i--) {
            if (count == rows) {
                std::cout << std::endl;
                count = 0;
            }

            std::cout << "[" << i;

            for (auto& player : players) {
                if (player->position == i) {
                    std::cout << " P" << player->player_number;
                }
            }

            if (jump_locations.count(i) > 0) {
                std::cout << " " << (i < jump_locations[i] ? "L:" : "S:") << " " << jump_locations[i];
            }

            std::cout << "]";

            count++;
        }

        std::cout << std::endl;
    }

    Node* start;
    Node* end;

    std::unordered_map<int, int> jump_locations; // node, its jump location
    std::vector<Player*> players;

    const int board_size = 100;
    const int cols = 10;
    const int rows = 10;
};

int main()
{
    srand(time(0));
    GameBoard gb;
    gb.simulateGame();

    return 0;
}