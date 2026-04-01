#include "HashTable.h"

HashTable::HashTable() : size_(256) {
	table_ = new Line[size_];
}

HashTable::~HashTable() {
	for (size_t i = 0; i < size_; ++i) {
		if (table_[i].occupied_) {
			delete[] table_[i].key_;
		}
	}
	delete[] table_;
}

HashIndex HashTable::hash(const char* str) const {
	HashIndex h = 0;
	int multiplier = 31;
	while (*str) {
		h = h * multiplier + *str++;
	}
	return h;
}

void HashTable::insert(const char* key) {
	if (number_ / size_ >= 0.7) {
		throw std::runtime_error("ERROR: Table is full\n");
	}

	size_t index = hash(key);
	int i = 0;

	while (table_[index].occupied_) {
		if (i == size_) {
			throw std::runtime_error("ERROR: Index out of range. Insertion is failed\n");
		}

		if (strcmp(table_[index].key_, key) == 0) {
			break;
		}

		i++;
		index += i * i;
		index %= size_;
	}

	table_[index] = Line(key);
	table_[index].occupied_ = true;
	++number_;
}

bool HashTable::search(const char* key) const {
	size_t index = hash(key);
	int i = 0;

	while (table_[index].occupied_ || table_[index].deleted_) {
		if (table_[index].occupied_ && strcmp(table_[index].key_, key) == 0) {
			return true;
		}
		i++;
		index += i * i;
		index %= size_;
		if (i == size_) {
			break;
		}
	}
	return false;
}

bool HashTable::remove(const char* key) {
	size_t index = hash(key);
	int i = 0;

	while (table_[index].occupied_) {
		if (strcmp(table_[index].key_, key) == 0) {
			delete[] table_[index].key_;
			table_[index].deleted_ = true;
			table_[index].occupied_ = false;
			--number_;
			return true;
		}
		i++;
		index += i * i;
		index %= size_;
		if (i == size_) {
			break;
		}
	}
	return false;
}

void HashTable::print() const {
	for (size_t i = 0; i < size_; i++) {
		if (table_[i].occupied_) {
			std::cout << table_[i].key_ << " ";
		}
	}
	std::cout << std::endl;
}

