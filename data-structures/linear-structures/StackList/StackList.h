#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "Stack.h"
#include <iostream>

template <typename T>
class StackList : public Stack<T>{
public:
    StackList() : top_(nullptr) {};
    StackList(const StackList& other) : top_(nullptr) {
        Node* current = other.top_;
        while (current) {
            T data = current->data_;
            Node* newNode = new Node(data);
            newNode->previous_ = top_;
            top_ = newNode;
            current = current->previous_;
        }
    }
    StackList(StackList&& other) noexcept : top_(other.top_) {
        other.top_ = nullptr;
    }
    ~StackList() override {
        clearStack();
    }

    StackList& operator=(const StackList& other) noexcept {
        if (this != &other) {
            delete top_;
            top_ = other.top_;
            Node* current = other.top_;
            while (current) {
                T data = current->data_;
                Node* newNode = new Node(data);
                newNode->previous_ = top_;
                top_ = newNode;
                current = current->previous_;
            }
        }
        return *this;
    }
    StackList& operator=(StackList&& other) noexcept {
        if (this != &other) {
            top_ = other.top_;
            other.top_ = nullptr;
        }
        return *this;
    }

    bool isEmpty() const override {
        return top_ == nullptr;
    }

    void push(const T& data) override {
        Node* newNode = new Node(data);
        newNode->previous_ = top_;
        top_ = newNode;
    }

    void* searchItem(const T& data) const {
        if (isEmpty()) {
            return nullptr;
        }

        Node* current = top_;
        while (current) {
            if (current->data_ == data) {
                return current;
            }
            current = current->previous_;
        }
        return nullptr;
    }

    T pop() override {
        if (isEmpty()) {
            throw StackUnderflow();
        }
        const Node* temp = top_;
        T poppedItem = temp->data_;
        top_ = top_->previous_;
        delete temp;
        return poppedItem;
    }

    const T& top() const override {
        return top_->data_;
    }

    void clearStack() {
        if (isEmpty()) {
            return;
        }

        Node* current = top_;
        Node* previousNode = nullptr;
        while (current) {
            previousNode = current->previous_;
            delete current;
            current = previousNode;
        }
        top_ = nullptr;
    }

    void print() const {
        if (isEmpty()) {
            return;
        }

        Node* current = top_;
        while (current) {
            std::cout << current->data_ << " ";
            current = current->previous_;
        }
        std::cout << std::endl;
    }

private:
    struct Node {
        T data_;
        Node* previous_;
        Node(const T& data) : data_(data), previous_(nullptr) {};
    };

    Node* top_{ nullptr };
};

#endif
