#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdexcept>
#include <iostream>
#include <cstring>

typedef unsigned char HashIndex;

class HashTable {
public:
	HashTable();
	~HashTable();

	HashTable(const HashTable& other) = delete;
	HashTable(HashTable&& other) = delete;
	HashTable& operator=(const HashTable& other) = delete;
	HashTable& operator=(const HashTable&& other) = delete;

	HashIndex hash(const char* str) const;
	void insert(const char* key);
	bool search(const char* key) const;
	bool remove(const char* key);
	void print() const;

		
private:
	struct Line {
		char* key_;
		bool occupied_;
		bool deleted_;

		Line() : key_(nullptr), occupied_(false), deleted_(false) {}
		Line(const char* key) : occupied_(false), deleted_(false) {
			if (key) {
				size_t len = strlen(key);
				key_ = new char[len + 1];
				for (size_t i = 0; i < len; ++i) {
					key_[i] = key[i];
				}
				key_[len] = '\0';
			}
			else {
				key_ = nullptr;
			}
		}
	};
	size_t size_{ 0 };
	Line* table_{ nullptr };
	int number_{ 0 };
};

#endif
