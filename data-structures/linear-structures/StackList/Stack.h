#ifndef STACK_H
#define STACK_H

#include "Exceptions.h"

template<typename T>
class Stack {
public:
    virtual ~Stack() {};
    virtual void push(const T& element) = 0;
    virtual T pop() = 0;
    virtual const T& top() const = 0;
    virtual bool isEmpty() const = 0;
};

#endif
