#include <iostream>
#include <cstdlib>
#include <ctime> 

struct Node {
	Node(int id, double gpa) : id(id), gpa(gpa), next(nullptr) {}

	int id;
	double gpa;
	Node* next;
};

struct LinkedList {
	LinkedList() : head(nullptr) {}

	// Add to back
	void push_back(int id, double gpa) {
		Node* temp = new Node(id, gpa);

		if (!head) {
			head = temp;
		} else {
			Node* current = head;

			while (current->next != nullptr) {
				current = current->next;
			}
			
			current->next = temp;
		}
		_size++;
	}

	// Add to front
	void push_front(int id, double gpa) {
		Node* temp = new Node(id, gpa);

		if (!head) {
			head = temp;
		} else {
			temp->next = head;
			head = temp;
		}
		_size++;
	}

	// Insert at index
	void insert(int id, double gpa, int index) {
		if (index > _size || index < 0) {
			std::cout << "Invalid index." << std::endl;
			return;
		}

		Node* temp = new Node(id, gpa);

		if (index == 0) {
			temp->next = head;
			head = temp;
		} else {
			Node* current = head;

			for (int i = 0; i < index - 1; ++i) {
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;
		}

		_size++;
	}

	// Print list
	void print_list() {
		if (!head) return;

		Node* current = head;
		while (current != nullptr) {
			std::cout << "ID: " << current->id << " GPA: " << current->gpa << std::endl;
			current = current->next;
		}
	}

	// Search for GPA (returns first occurence)
	int search_gpa(double gpa) {
		if (!head) return 0;

		Node* current = head;

		while (current != nullptr) {
			if (std::abs(current->gpa - gpa) < 1e-6) {
            	return current->id;
        	}
			current = current->next;
		}

		return 0;
	}

	// Search for GPA (bool)
	bool search_gpa_bool(double gpa) {
		if (!head) return false;

		Node* current = head;

		while (current != nullptr) {
			if (std::abs(current->gpa - gpa) < 1e-6) {
            	return true;
        	}
			current = current->next;
		}

		return false;
	}

	// Return size
	int size() {
		return _size;
	}

private:
	Node* head;
	int _size = 0;
};

int main() 
{
	LinkedList l;

	int n_students = 50;
	double desired_gpa = 2.8;

	// Randomly generate n students, add to back
	std::srand(std::time(nullptr));
	
	for (int i = 0; i < n_students; i++) {
	    int id = 1000 + (std::rand() % 4001);
	    double gpa = 2.0 + (std::rand() % 201) / 100.0;
	    l.push_back(id, gpa);                        
	}

	// Add one more to the front
	l.push_front(1000, 4.0);

	// Insert student at index 1
	l.insert(1001, 3.9, 1);

	// Insert at invalid index (error)
	l.insert(3232, 2.4, -5);

	// Print list and size
	std::cout << "Students: " << std::endl;
	l.print_list();
	std::cout << "Size of list: " << l.size() << std::endl;

	std::cout << std::endl;

	// Search for GPA, return ID
	std::cout << "Searching for GPA: " << desired_gpa << std::endl;
	int found_id = l.search_gpa(desired_gpa);
	if (found_id) {
		std::cout << "ID: " << found_id << " has the GPA " << desired_gpa << std::endl;
	} else {
		std::cout << "GPA: " << desired_gpa << " was not found. " << std::endl;
	}

	// Search for GPA, return bool
	std::cout << "Searching for GPA: (bool) " << desired_gpa << std::endl;
	
	if (l.search_gpa_bool(desired_gpa)) {
		std::cout << "GPA: " << desired_gpa << " was found." << std::endl;
	} else {
		std::cout << "GPA: " << desired_gpa << " was not found. " << std::endl;
	}

	return 0;
}