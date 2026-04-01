#ifndef QUEUE_VECTOR_H
#define QUEUE_VECTOR_H

#include "Queue.h"
#include <iostream>

template <class T>
class QueueVector : public Queue<T> {
public:
    QueueVector() : capacity_(100), head_(0), tail_(0), size_(0) {
        array_ = new T[capacity_];
    }
    QueueVector(const int capacity) : capacity_(capacity), head_(0), tail_(0), size_(0) {
        if (capacity <= 0) {
            throw WrongQueueSize();
        }
        array_ = new T[capacity_];
    }
    QueueVector(const QueueVector& object) : capacity_(object.capacity_), head_(object.head_), tail_(object.tail_), size_(object.size_) {
        array_ = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            array_[(head_ + i) % capacity_] = object.array_[(head_ + i) % capacity_];
        }
    }
    QueueVector(QueueVector&& object) noexcept : array_(object.array_),  capacity_(object.capacity_), head_(object.head_), tail_(object.tail_), size_(object.size_) {
        object.array_ = nullptr;
        object.head_ = 0;
        object.tail_ = 0;
        object.capacity_ = 0;
        object.size_ = 0;
    }
    QueueVector& operator=(const QueueVector& object) noexcept {
        if (this != &object) {
            capacity_ = object.capacity_;
            head_ = object.head_;
            tail_ = object.tail_;
            size_ = object.size_;

            delete[] array_;
            array_ = new T[capacity_];
            for (int i = 0; i < size_; i++) {
                array_[(head_ + i) % capacity_] = object.array_[(head_ + i) % capacity_];
            }
        }
        return *this;
    }
    QueueVector& operator=(const QueueVector&& object) noexcept {
        if (this != &object) {
            delete[] array_;
            array_ = object.array_;
            capacity_ = object.capacity_;
            head_ = object.head_;
            tail_ = object.tail_;
            size_ = object.size_;

            object.array_ = nullptr;
            object.head_ = 0;
            object.tail_ = 0;
            object.capacity_ = 0;
            object.size_ = 0;
        }
        return *this;
    }
    ~QueueVector() override {
        delete[] array_;
    }

    void enQueue(const T& e) override {
        if (size_ == capacity_) {
            resize();
        }

        array_[tail_] = e;
        tail_ = (tail_ + 1) % capacity_;
        size_++;
    }

    T deQueue() override {
        if (isEmpty()) {
            throw QueueUnderflow();
        }
        T value = array_[head_];
        head_ = (head_ + 1) % capacity_;
        size_--;
        return value;
    }

    T getHead() const {
        T value = array_[head_];
        return value;
    }

    bool isEmpty() const override {
        return tail_ == head_;
    }

    void print() const {
        for (int i = 0; i < size_; i++) {
            int index = (head_ + i) % capacity_;
            std::cout << array_[index] << " ";
        }
        std::cout << std::endl;
    }

private:
    T* array_{nullptr};
    int capacity_{0};
    int head_{0};
    int tail_{0};
    int size_{0};

    void resize() {
        int newCapacity = capacity_ * 2;
        T* newArray = new T[newCapacity];

        for (int i = 0; i < size_; i++) {
            newArray[i] = array_[(head_ + i) % capacity_];
        }

        delete [] array_;
        array_ = newArray;
        head_ = 0;
        tail_ = size_;
        capacity_ = newCapacity;
    }
};

#endif
