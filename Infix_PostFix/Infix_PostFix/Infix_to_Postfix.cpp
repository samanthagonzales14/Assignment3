#include "Infix_to_Postfix.h"
#include <cctype>
using std::string;

const string Infix_to_Postfix::OPS = "+-*/%(){}[]";	// operators
const int Infix_to_Postfix::PRECEDENCE[] = { 1, 1, 2, 2, 2, -1, -1, -1, -1, -1, -1 }; // corresponding precedence for operators

string Infix_to_Postfix::convert(const std::string& expression) {
	postfix = "";		// set postfix to empty string
	while (!op_stack.Empty())
		op_stack.Pop();
	char next_token;

	for (int i = 0; i < expression.length(); i++) {	// iterates through infix expression character by character
		next_token = expression[i];
		if (isalnum(next_token)) {	// if character is a number or alphabet letter adds to postfix expression
			postfix += next_token;
			postfix += " ";
		}
		else if (is_operator(next_token)) {	// if charcter is an operator calls function to process operator accordingly
			process_operator(next_token);
		}
		else if (next_token == ' ') {	// if character is a space do nothing
			postfix += "";				// prevents syntax error from being thrown
		}
		else {
			throw syntax_error("Unexpected character encountered.");	// if character is not an operator, letter, or number throw syntax error
		}
	}
	
	while (!op_stack.Empty()) {		// traverse through stack to return postfix expression
		char op = op_stack.Top();
		op_stack.Pop();
		postfix += op;
		postfix += " ";
	}
	return postfix;		// return postfix expression
}

void Infix_to_Postfix::process_operator(char op) {
	if (op_stack.Empty() || (op == '(') || (op == '{') || (op == '[')) {	// if stack is empty or operator is a left parenthese push onto stack
		op_stack.Push(op);
	}
	else {
		if (precedence(op) > precedence(op_stack.Top())) {	// if the operator has greater precedence than the op on top of stack add the operator to top of stack
			op_stack.Push(op);
		}
		else {
			while (!op_stack.Empty() && op_stack.Top() != '(' && op_stack.Top() != '{' && op_stack.Top() != '['	// if operator stack is not empty and top of stack is not a left parenthese
				&& (precedence(op) <= precedence(op_stack.Top()))) {						// and precedence of current operator is less than operatoe on top of stack
				postfix += op_stack.Top();	// append operator on top of stack to postfix expression
				postfix += " ";				// add a space
				op_stack.Pop();				// remove from stack
			}
			if (op == ')' || op == '}' || op == ']') {	// if current operator is a right parenthese 
				while (op_stack.Top() == '(' && op_stack.Top() == '{' && op_stack.Top() == '[') {	// pop and add to output operagtor from the stack the top of stack  until a left parenthese is encountered
					postfix += op_stack.Top();						// append operator on top of stack to postfix expression
					postfix += " ";							// add a space
					op_stack.Pop();							// remove from stack
				}
				op_stack.Pop();								// remove left parenthese from stack
			}
			else {
				op_stack.Push(op);	// otherwise add to stack
			}
		}
	}
}
