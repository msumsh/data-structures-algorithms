#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class StackUnderflow : public std::exception {
public:
	StackUnderflow() : reason_("Stack Underflow") {};
	const char* what() const noexcept override {
	    return reason_;
	}
private:
	const char* reason_;
};

#endif

