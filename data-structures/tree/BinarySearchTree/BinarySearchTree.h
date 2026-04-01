#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "QueueVector.h"
#include <iostream>

template <class T>
class BinarySearchTree {
public:
    BinarySearchTree() : root_(nullptr) {};
    BinarySearchTree(const BinarySearchTree<T>& tree) = delete;
    BinarySearchTree(BinarySearchTree<T>&& tree) noexcept {
        root_ = tree.root_;
        tree.root_ = nullptr;
    }
    ~BinarySearchTree() {
        destroyTree(root_);
    }

    BinarySearchTree& operator=(const BinarySearchTree<T>& tree) = delete;
    BinarySearchTree& operator=(BinarySearchTree<T>&& tree) noexcept {
        if (this != &tree) {
            delete root_;
            root_ = tree.root_;
            tree.root_ = nullptr;
        }
        return *this;
    }

    bool searchIterative(const T& key) const {
        if (searchIterativePrivate(key)) {
            return true;
        }
        else {
            return false;
        }
    }

    bool insert(const T& key) {
        if (searchIterative(key)) {
            return false;
        }

        Node* newNode = new Node(key);
        Node* parent = nullptr;
        Node* current = root_;

        while (current != nullptr) {
            parent = current;
            if (key < current->key_) {
                current = current->left_;
            }
            else {
                current = current->right_;
            }
        }

        newNode->parent_ = parent;
        if (parent == nullptr) {
            root_ = newNode;
        }
        else if (key < parent->key_) {
            parent->left_ = newNode;
        }
        else {
            parent->right_ = newNode;
        }
        return true;
    }

    bool remove(const T& key) {
        Node* current = root_;
        Node* previous = nullptr;

        //-----key search-----
        while (current != nullptr && current->key_ != key) {
            previous = current;
            if (key < current->key_) {
                current = current->left_;
            }
            else {
                current = current->right_;
            }
        }

        //-----not found-----
        if (current == nullptr) {
            return false;
        }

        //-----zero or one child node-----
        if (current->left_ == nullptr || current->right_ == nullptr) {
            Node* newCurrent;
            if (current->left_ == nullptr) {
                newCurrent = current->right_;
            }
            else {
                newCurrent = current->left_;
            }
            if (previous == nullptr) {
                root_ = newCurrent;
                delete current;
                return true;
            }
            if (current == previous->left_) {
                previous->left_ = newCurrent;
            }
            else {
                previous->right_ = newCurrent;
            }
            delete current;
            return true;
        }

        //-----two child nodes-----
        Node* parent = nullptr;
        Node* temp = current->right_;
        while (temp->left_ != nullptr) {
            parent = temp;
            temp = temp->left_;
        }

        if (parent != nullptr) {
            parent->left_ = temp->right_;
        }
        else {
            current->right_ = temp->right_;
        }
        current->key_ = temp->key_;
        delete temp;
        return true;
    }

    void output(std::ostream& out) const {
        output(out, root_);
    }

    int getNumberOfNodes() const {
        return getNumberOfNodes(root_);
    }

    int getHeight() const {
        return getHeight(root_);
    }

    void inorderWalkRecursive() const {
        inorderWalkRecursive(root_);
        std::cout << std::endl;
    }

    void inorderWalkIterative() const {
        inorderWalkIterative(root_);
        std::cout << std::endl;
    }

    void walkByLevels() const {
        if (!root_) {
            return;
        }
        QueueVector<Node*> q;
        q.enQueue(root_);
        while (!q.isEmpty()) {
            Node* node = q.deQueue();
            std::cout << node->key_ << " ";
            if (node->left_) {
                q.enQueue(node->left_);
            }
            if (node->right_) {
                q.enQueue(node->right_);
            }
        }
        std::cout << std::endl;
    }

    T searchMinimalElement(int k) const {
        if (k <= getNumberOfNodes(root_)) {
            T result = 0;
            searchMinimalElement(root_, k, result);
            return result;
        }
        else {
            throw std::invalid_argument("Invalid k value\n");
        }
    }

private:
    struct Node {
        T key_;
        Node* left_;
        Node* right_;
        Node* parent_;
        Node(const T& key) : key_(key), left_(nullptr), right_(nullptr), parent_(nullptr) {};
    };
    Node* root_{nullptr};

    Node* searchIterativePrivate(const T& key) const {
        Node* current = root_;
        while (current != nullptr) {
            if (current->key_ < key) {
                current = current->left_;
            }
            else if (current->key_ > key) {
                current = current->right_;
            }
            else {
                return current;
            }
        }
        return nullptr;
    }

    void output(std::ostream& out, const Node* node) const {
        if (node != nullptr) {
            out << node->key_;
            if (node->left_ || node->right_) {
                out << "(";
                if (node->left_) {
                    output(out, node->left_);
                }
                if (node->right_) {
                    if (node->left_) {
                        out << ",";
                    }
                    output(out, node->right_);
                }
                out << ")";
            }
        }
        else {
            out << "()";
        }
    }

    int getNumberOfNodes(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return (1 + getNumberOfNodes(node->left_) + getNumberOfNodes(node->right_));
    }

    int getHeight(const Node* node) const {
        if (node == nullptr) {
            return -1;
        }
        int leftSubTreeHeight = getHeight(node->left_);
        int rightSubTreeHeight = getHeight(node->right_);
        if (leftSubTreeHeight > rightSubTreeHeight) {
            return 1 + leftSubTreeHeight;
        }
        else {
            return 1 + rightSubTreeHeight;
        }
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left_);
            destroyTree(node->right_);
            delete node;
        }
    }

    void inorderWalkRecursive(Node* node) const {
        if (node != nullptr) {
            inorderWalkRecursive(node->left_);
            std::cout << node->key_ << " ";
            inorderWalkRecursive(node->right_);
        }
    }

    void inorderWalkIterative(Node* node) const {
        Node* current = node;
        Node* previous = node->parent_;

        while (current != nullptr) {
            if (current->left_ == nullptr) {
                std::cout << current->key_ << " ";
                current = current->right_;
            }
            else {
                previous = current->left_;
                while (previous->right_ != nullptr && previous->right_ != current) {
                    previous = previous->right_;
                }

                if (previous->right_ == nullptr) {
                    previous->right_ = current;
                    current = current->left_;
                }
                else {
                    previous->right_ = nullptr;
                    std::cout << current->key_ << " ";
                    current = current->right_;
                }
            }
        }
    }

    void searchMinimalElement(Node* node, int& k, T& result) const {
        if (node != nullptr) {
            searchMinimalElement(node->left_, k, result);
            k--;
            if (k == 0) {
                result = node->key_;
                return;
            }
            searchMinimalElement(node->right_, k, result);
        }
    }
};

#endif
