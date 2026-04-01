#include "getPostfixFromInfix.h"

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

void getPostfixFromInfix(const char* infix, char* postfix) {
	StackList<char> stack;

	int pos = 0;
	int bracesCount = 0;
	for (int i = 0; infix[i] != '\0'; i++) {
		char element = infix[i];

		if (element == ' ') {
			continue;
		}
		if (isdigit(element)) {
			postfix[pos] = element;
			pos++;
		}
		else if (element == '(') {
			bracesCount++;
			stack.push(element);
		}
		else if (element == ')') {
			bracesCount--;
			while (!stack.isEmpty() && stack.top() != '(') {
				postfix[pos] = stack.top();
				pos++;
				stack.pop();
			}

			if (stack.isEmpty()) {
				throw std::invalid_argument("Invalid infix expression\n");
			}

			stack.pop();
		}
		else if (element == '+' || element == '-' || element == '*' || element == '/') {
			while (!stack.isEmpty() && precedence(stack.top()) >= precedence(element)) {
				postfix[pos] = stack.top();
				pos++;
				stack.pop();
			}
			stack.push(element);
		}
		else {
			throw std::invalid_argument("Invalid character in expression");
		}
	}

	if (bracesCount != 0) {
		throw std::invalid_argument("Invalid infix expression\n");
	}

	while (!stack.isEmpty()) {
		postfix[pos] = stack.top();
		pos++;
		stack.pop();
	}

	postfix[pos] = '\0';
}
