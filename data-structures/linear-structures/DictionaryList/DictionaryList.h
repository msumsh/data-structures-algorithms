#ifndef DICTIONARY_LIST
#define DICTIONARY_LIST

#include <iostream>

template <typename T>
class DictionaryList {
public:
	DictionaryList() : head(nullptr) {};
	DictionaryList(const DictionaryList& other) : head(nullptr) {
		Node* current = other.head;
		while (current) {
			insertItem(current->key);
			current = current->next;
		}
	}
	DictionaryList(DictionaryList&& other) noexcept : head(other.head) {
		other.head = nullptr;
	}
	~DictionaryList() { 
		clear(); 
	}

	DictionaryList& operator=(DictionaryList&& other) noexcept {
		if (this != &other) {
			head = other.head;
			other.head = nullptr;
		}
		return *this;
	}


	bool isEmpty() const {
		return head == nullptr;
	}

	void insertItem(const T& key) {
		if (searchItem(key)) {
			return;
		}

		Node* newNode = new Node(key);
		if (!head || head->key > key) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* current = head;
		while (current->next && current->next->key < key) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	void* searchItem(const T& key) const {
		if (isEmpty()) {
			return nullptr;
		}

		Node* current = head;
		while (current) {
			if (current->key == key) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

	void deleteItem(const T& key) {
		if (!searchItem(key) || isEmpty()) {
			return;
		}

		if (head->key == key) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* current = head;
		while (current->next && current->next->key != key) {
			current = current->next;
		}

		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}

	void clear() {
		if (isEmpty()) {
			return;
		}

		Node* current = head;
		Node* nextNode = nullptr;
		while (current) {
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
		head = nullptr;
	}

	void print() const {
		if (isEmpty()) {
			return;
		}

		Node* current = head;
		while (current) {
			std::cout << current->key << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	friend DictionaryList getIntersection(const DictionaryList& dictOne, const DictionaryList& dictTwo) {
		DictionaryList newDict;
		Node* currentOne = dictOne.head;
		Node* currentTwo = dictTwo.head;

		while (currentOne && currentTwo) {
			if (currentOne->key < currentTwo->key) {
				currentOne = currentOne->next;
			}
			else if (currentOne->key > currentTwo->key) {
				currentTwo = currentTwo->next;
			}
			else {
				newDict.insertItem(currentOne->key);
				currentOne = currentOne->next;
				currentTwo = currentTwo->next;
			}
		}
		
		return newDict;
	}

private:
	struct Node {
		T key;
		Node* next;
		Node(const T& key) : key(key), next(nullptr) {};
	};

	Node* head{ nullptr };
};

#endif