#include <iostream>
#include <stdexcept>

// Example of a simple dynamic array class

class DynamicArray {
public:
	DynamicArray(int _size) : _size(_size) {
		if (_size <= 0) {
			throw std::invalid_argument("Invalid Size");
		}

		array = new int[_size];
	}

	~DynamicArray() {
		delete[] array;
	}

	void insert(int item) {
		if (_size == count) {
			int* new_array = new int[count * 2];

			for (int i = 0; i < count; i++) {
				new_array[i] = array[i];
			}

			delete[] array;
			array = new_array;
			_size *= 2;
		}

		array[count++] = item;
	}

	void remove(int index) {
		if (index < 0 || index >= count) {
			throw std::invalid_argument("Invalid Index");
		}

		for (int i = index; i < count; i++) {
			array[i] = array[i + 1];
		}

		count--;
	}

	int indexOf(int item) const {
		for (int i = 0; i < count; i++) {
			if (array[i] == item) return i;
		}

		return -1;
	}

	int at(int index) const {
		if (index < 0 || index >= count) {
			throw std::invalid_argument("Invalid Index");
		}

		return array[index];
	}

	void clear() {
    	count = 0;
	}	

	int size() const {
		return count;
	}

	void print() const {
		for (int i = 0; i < count; i++) {
			std::cout << array[i] << std::endl;
		}
	}

	bool empty() const {
		return count == 0;
	}

private:
	int* array;
	int _size;
	int count = 0;
};

int main()
{
	DynamicArray a(5);
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);

	a.print();

	a.remove(2);

	a.print();
	
	return 0;
}