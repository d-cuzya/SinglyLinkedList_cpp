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
	void remove() {
		Item* tmp = first_item;
		first_item = first_item->next_pointer;
		delete(tmp);
	}
	void Delete() {
		Item* tmp = first_item;
		Item* previus = nullptr;
		while (tmp->next_pointer != nullptr) {
			previus = tmp;
			tmp = tmp->next_pointer;
		}
		delete(tmp);
		previus->next_pointer = nullptr;
	}
	int size() {
		int i = 1;
		Item* tmp = first_item;
		while (tmp->next_pointer != nullptr) {
			tmp = tmp->next_pointer;
			i++;
		}
		return i;
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
	std::cout << "Add to End 4 elements:\n";
	singlyLinked.append(6);
	singlyLinked.append(5);
	singlyLinked.append(9);
	singlyLinked.append(2);
	singlyLinked.iterate();
	std::cout << "Add to Start 3 elemnts:\n";
	singlyLinked.insert(2);
	singlyLinked.insert(10);
	singlyLinked.insert(-1);
	singlyLinked.iterate();
	std::cout << "Delete 2 items from Start:\n";
	singlyLinked.remove();
	singlyLinked.remove();
	singlyLinked.iterate();
	std::cout << "Delete 2 items from End:\n";
	singlyLinked.Delete();
	singlyLinked.Delete();
	singlyLinked.iterate();
	std::cout << "Size: " << singlyLinked.size() << "\n";
}