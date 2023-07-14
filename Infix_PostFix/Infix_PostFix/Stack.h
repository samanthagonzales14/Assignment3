#include <vector>
#pragma once

template<typename Item_Type>		// Stack to hold any data type
class Stack {
private:
	std::vector<Item_Type> container;	// container to hold stack
public:
	Stack();		// Constructor to intialize empty stack
	Item_Type& Top();	// Pre- No parameters -- Post- Returns item at top of stack
	void Pop();			// Pre- Modifier, No parameters -- Post- Removes item at top of stack
	bool Empty() const;	// Pre- No parameters -- Post- Returns true if stack is empty, false otherwise
	void Push(const Item_Type& item);	// Pre- Takes item to be added to stack as parameter -- Post- pushes item onto top of stack
	size_t Size() const;		// Pre- No parameters -- Post- Returns number of items in stack
};


