#include <iostream>

struct Pearl {
	Pearl(int color) : color(color) {}
	int color;
	Pearl* next;
};

struct Necklace {
	Necklace() : head(nullptr), tail(nullptr) {}

	void addFront(int color) {
		Pearl* pearl = new Pearl(color);

		if (!head) {
			head = pearl;
			tail = pearl;
		} else {
			pearl->next = head;
			head = pearl;
		}

		_size++;
	}

	void addEnd(int color) {
		Pearl* pearl = new Pearl(color);

		if (!head) {
			head = pearl;
			tail = pearl;
		} else {
			tail->next = pearl;
			tail = pearl;
		}

		_size++;
	}

	// adds at index. if index is > size of list, add at end
	void addAt(int color, int index) {
		if (index < 0) return;

		if (index >= _size) {
			addEnd(color);
		} else if (index == 0) {
			addFront(color);
		} else {
			Pearl* pearl = new Pearl(color);
			Pearl* current = head;

			for (int i = 0; i < index - 1; ++i) {
				current = current->next;
			}
			pearl->next = current->next;
			current->next = pearl;
		}

		_size++;
	}

	// Adds before the first occurence of a specfic color
	void addBefore(int new_color, int color) {
		Pearl* current = head;
		Pearl* prev = nullptr;

		while (current) {
			if (current->color == color) {
				Pearl* pearl = new Pearl(new_color);
				pearl->next = current;
				if (prev) {
					prev->next = pearl;
				} else {
					head = pearl;
				}
				_size++;
				break;
			}
			prev = current;
			current = current->next;
		}
	}

	// Adds after the first occurence of a specfic color
	void addAfter(int new_color, int color) {
		Pearl* current = head;

		while (current) {
			if (current->color == color) {
				Pearl* pearl = new Pearl(new_color);
				pearl->next = current->next;
				current->next = pearl;
				_size++;
				break;
			}
			current = current->next;
		}
	}

	// Removes all occurences of a color
	void removeColor(int color) {
		Pearl* current = head;
		Pearl* prev = nullptr;

		while (current) {
			if (current->color == color) {
				if (prev) {
					prev->next = current->next;
					delete current;
					current = prev->next;
				} else {
					head = current->next;
					delete current;
					current = head;
				}
				_size--;
			} else {
				prev = current;
				current = current->next;
			}
		}
	}

	// Removes given index and returns the color
	int removeIndex(int index) {
		if (index < 0 || index > _size - 1) return -1;

		Pearl* current = head;
		int color;

		if (index == 0) {
			head = head->next;
			color = current->color;

			if (head == nullptr) {
	            tail = nullptr;
	        }

	        delete current;

	        return color;
		}
		
		for (int i = 0; i < index - 1; ++i) {
			current = current->next;
		}
		Pearl* prev = current;
		current = current->next;

		color = current->color;

		prev->next = current->next;
		current->next = nullptr;
		delete current;

		_size--;

		return color;
	}

	// Returns color at index
	int at(int index) {
		if (index > _size - 1 || index < 0) {
			return -1;
		} else {
			Pearl* current = head;
			for (int i = 0; i < index; ++i) {
				current = current->next;
			}
			return current->color;
		}
	}

	// Search for pearl color in necklace. Returns boolean value
	bool find(int color) {
		Pearl* current = head;
		while (current) {
			if (current->color == color) return true;
			current = current->next;
		}
		return false;
	}

	void printNecklace() {
		Pearl* current = head;

		while (current) {
			std::cout << "Color: " << current->color << std::endl;
			current = current->next;
		}
	}

	int size() {
		return _size;
	}
 
private:
	Pearl* head;
	Pearl* tail;
	int _size = 0;
};

int main() 
{
	Necklace n;

	// Populate Necklace
	n.addEnd(3);
	n.addEnd(70);
	n.addEnd(99);
	n.addFront(5);
	n.addEnd(4);
	n.addAt(10, 3);
	n.addAt(10, 4);

	// Add 1 before 3
	n.addBefore(1, 3);

	// Add 37 add 99
	n.addAfter(37, 99);

	// Print Necklace
	std::cout << "Necklace:" << std::endl;
	n.printNecklace();
	std::cout << "Size: " << n.size() << std::endl;

	// Remove at index 2
	std::cout << "Removing index 2. Color: " << n.removeIndex(2) << std::endl;

	// Print color at index 3
	std::cout << "Color at index 3:" << std::endl;
	std::cout << n.at(3) << std::endl;

	// Remove all '10' colors
	n.removeColor(10);

	// Find if colors 4 and 81 are in the list
	if (n.find(4)) {
		std::cout << "Color 4 is in the necklace." << std::endl;
	} else {
		std::cout << "Color 4 is not in the necklace." << std::endl;
	}

	if (n.find(81)) {
		std::cout << "Color 81 is in the necklace." << std::endl;
	} else {
		std::cout << "Color 81 is not in the necklace." << std::endl;
	}

	// Print Necklace
	std::cout << "Necklace:" << std::endl;
	n.printNecklace();
	std::cout << "Size: " << n.size() << std::endl;

	return 0;
}