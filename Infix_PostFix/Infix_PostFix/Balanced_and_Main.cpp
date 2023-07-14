#include "Stack.cpp"
#include "Infix_to_Postfix.h"
#include <string>
#include <iostream>
using namespace std;


const string OPEN = "([{";
const string CLOSE = ")]}";

bool is_open(char ch) {		// Returns true if character is left parenthese
	return OPEN.find(ch) != string::npos;	
}

bool is_closed(char ch) {	// Returns true if character is right parenthese
	return CLOSE.find(ch) != string::npos;
}

bool is_balanced(const string& expression) {	// Returns true if all parenthese match
	Stack<char> p;
	bool balanced = true;
	string::const_iterator iter = expression.begin();

	while (balanced && (iter != expression.end())) {	// while balanced is true and not end of expression
		char next = *iter;
		if (is_open(next)) {	// check for left parenthese
			p.Push(next);	// add to stack
		}
		else if (is_closed(next)) {	// check for right parenthese
			if (p.Empty()) {		// if empty stack
				balanced = false;	// balance is false
			}
			else {
				char top_ch = p.Top();	
				p.Pop();
				balanced = OPEN.find(top_ch) == CLOSE.find(next);	// check if left and right parenthese are balanced
			}
		}
		++iter;		// next iterator
	}
	return balanced && p.Empty();	
}

int main() {
	Infix_to_Postfix infix_to_postfix;	// create class object

	cout << "Enter an expression: ";
	string expression;
	while (getline(cin, expression) && (expression != "")) {	// read in user input, exit program if user enters empty string
		cout << "\nInfix Expression: " << expression;
		if (is_balanced(expression)) {						// determine if infix expression is balanced
			try {											// if so convert to postfix expression
				string result = infix_to_postfix.convert(expression);
				cout << "\nPostfix Expression: " << result << endl;
			}
			catch (syntax_error& ex) {
				cout << "\nSyntax Error: " << ex.what() << endl;	// catch syntax errors
			}
		}
		else {										// if infix expression is not balanced output message 
			cout << " is not balanced.\n";
		}
		cout << "\nEnter another expression: ";		// prompt for new expression from user
	}
	return 0;
}