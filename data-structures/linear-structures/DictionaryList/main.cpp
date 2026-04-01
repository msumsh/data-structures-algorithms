#include "DictionaryList.h"
#include <string>

int main() {
    DictionaryList<std::string> dict1;
    dict1.insertItem("dog"); 
    dict1.insertItem("cat");
    dict1.insertItem("bird");
    dict1.insertItem("cat"); 
    dict1.insertItem("mouse");
    std::cout << "First dictionary: ";
    dict1.print(); 

    std::cout << "Search 'cat': " << dict1.searchItem("cat") << std::endl;
    dict1.deleteItem("cat"); 
    std::cout << "First dictionary after using deleteItem: "; 
    dict1.print();

    DictionaryList<std::string> dict2;
    dict2.insertItem("dog");
    dict2.insertItem("mouse");
    dict2.insertItem("butterfly");
    std::cout << "Second dictionary: ";
    dict2.print();

    DictionaryList<std::string> result = getIntersection(dict1, dict2);
    std::cout << "First dictionary: ";
    dict1.print();
    std::cout << "Second dictionary: ";
    dict2.print();
    std::cout << "Intersection: ";
    result.print();

    dict1.clear();
    dict1.print();
	return 0;
}
