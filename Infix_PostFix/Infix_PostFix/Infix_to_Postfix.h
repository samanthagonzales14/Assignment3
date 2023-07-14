#include <string>
#include <stdexcept>
#include "Stack.h"

class Infix_to_Postfix {
private:
	void process_operator(char op);	// Pre - takes a character operator as parameter -- Post- Processes operator for precendence
	bool is_operator(char ch) const {	// Pre- takes a character operator as parameter -- Post- Returns true if character is an operator
		return OPS.find(ch) != std::string::npos;
	};
	int precedence(char op) const {	// Pre- takes a character operator as parameter -- Post- Returns precedence of operator
		return PRECEDENCE[OPS.find(op)];
	};
	static const std::string OPS;	// fixed operators
	static const int PRECEDENCE[];	// fixed precedence for operators
	Stack<char> op_stack;			// stack to store operators
	std::string postfix;			// string to store postfix expression
public:
	std::string convert(const std::string& expression);	// Pre- takes a infix string as parameter -- Post- Returns Postfix expression
};

class syntax_error : public std::invalid_argument {		// Class to throw syntax error message
public:
	syntax_error(std::string excpt) : std::invalid_argument(excpt){}
};