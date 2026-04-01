#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class QueueUnderflow: public std::exception {
public:
    const char* what() const noexcept override {
        return reason_;
    }
private:
    const char* reason_{"Queue underflow"};
};

class WrongQueueSize: public std::exception {
public:
    const char* what() const noexcept override {
        return reason_;
    }
private:
    const char* reason_{"Wrong queue size"};
};


#endif
