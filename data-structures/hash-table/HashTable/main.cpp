#include "HashTable.h"

int main() {
	HashTable hashTable;
	try {
		std::cout << "-----Insert items-----\n";
		hashTable.insert("abc");
		hashTable.insert("def");
		hashTable.insert("fed");
		hashTable.insert("abc");

		hashTable.print();

		std::cout << "-----Search \"abc\" and \"xyz\"-----\n";
		std::cout << (hashTable.search("abc") ? "True\n" : "False\n");
		std::cout << (hashTable.search("xyz") ? "True\n" : "False\n");

		std::cout << "-----Remove \"abc\" and \"fed\"-----\n";
		std::cout << (hashTable.remove("abc") ? "True\n" : "False\n");
		std::cout << (hashTable.remove("fed") ? "True\n" : "False\n");

		std::cout << "------Hash table after-----\n";
		hashTable.print();
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return 0;
}
