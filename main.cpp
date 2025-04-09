#include <iostream>

class SinglyLinkedList {
private:
	class Item {
	public:
		Item(int _value, Item* _next_pointer) {
			value = _value;
			next_pointer = _next_pointer;
		}
		int value;
		Item* next_pointer = nullptr;
	};
	Item* first_item = nullptr;
public:
	void append(int _value) {
		Item* tmpPtr = first_item;
		if (first_item == nullptr) {
			Item* newItem = new Item(_value, nullptr);
			first_item = newItem;
		}
		else {
			while (tmpPtr->next_pointer != nullptr) {
				tmpPtr = tmpPtr->next_pointer;
			}
			Item* newItem = new Item(_value, nullptr);
			tmpPtr->next_pointer = newItem;
		}
	}
	void insert(int _value) {
		Item* newItem = new Item(_value, first_item);
		first_item = newItem;
	}
	void iterate() {
		int index = 1;
		Item* tmpPtr = first_item;
		while (tmpPtr->next_pointer != nullptr) {
			std::cout << index << " : " << tmpPtr->value << "\n";
			index++;
			tmpPtr = tmpPtr->next_pointer;
		}
		std::cout << index << " : " << tmpPtr->value << "\n";
	}
};

int main() {
	SinglyLinkedList singlyLinked;
	singlyLinked.append(6);
	singlyLinked.append(5);
	singlyLinked.append(9);
	singlyLinked.append(2);
	singlyLinked.iterate();
	std::cout << "============\n";
	singlyLinked.insert(2);
	singlyLinked.iterate();
}