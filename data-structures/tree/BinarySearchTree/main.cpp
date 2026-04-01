#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> tree;

    //-----insert-----
    std::cout << "Inserting nodes: 2, 3, 4, 5, 6, 7, 8, 9\n";
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.output(std::cout);
    std::cout << std::endl;

    //-----searchIterative-----
    std::cout << "Search 7: " << ((tree.searchIterative(2)) ? "Found\n" : "Not Found\n");
    std::cout << "Search 15: " << ((tree.searchIterative(15)) ? "Found\n" : "Not Found\n");

    //-----getNumberOfNodes-----
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";

    //-----getHeight-----
    std::cout << "Tree height: " << tree.getHeight() << "\n";

    //-----InorderWalkRecursive-----
    std::cout << "Inorder Walk Recursive: ";
    tree.inorderWalkRecursive();

    //-----InorderWalkIterative-----
    std::cout << "Inorder Walk Iterative: ";
    tree.inorderWalkIterative();

    //-----WalkByLevels-----
    std::cout << "Walk by levels: ";
    tree.walkByLevels();

    //-----remove-----
    std::cout << "Removing 2: " << (tree.remove(2) ? "Removed" : "Not Found") << "\n";
    std::cout << "Removing 4: " << (tree.remove(4) ? "Removed" : "Not Found") << "\n";
    std::cout << "Removing 9: " << (tree.remove(9) ? "Removed" : "Not Found") << "\n";
    std::cout << "Removing 14: " << (tree.remove(14) ? "Removed" : "Not Found") << "\n";
    tree.output(std::cout);
    std::cout << std::endl;

    //-----searchMinimalElement-----
    try {
        int kthMinElem = tree.searchMinimalElement(3);
        std::cout << "Third minimal element = " << kthMinElem << std::endl;
        kthMinElem = tree.searchMinimalElement(6);
        std::cout << "Sixth minimal element = " << kthMinElem << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}