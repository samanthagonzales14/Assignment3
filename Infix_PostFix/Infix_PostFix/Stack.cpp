#include "Stack.h"

template<typename Item_Type>
Stack<Item_Type>::Stack() { }	// Intializes an empty stack

template<typename Item_Type>
Item_Type& Stack<Item_Type>::Top(){
	return container.back();	// Returns item on top of stack without removing it
}

template<typename Item_Type>
void Stack<Item_Type>::Pop(){	// Removes item at top of stack
	container.pop_back();
}

template<typename Item_Type>
bool Stack<Item_Type>::Empty() const{	// Returns true if stack is empty. Otherwise returns false.
	return container.empty();
}

template<typename Item_Type>
void Stack<Item_Type>::Push(const Item_Type& item) {	// Pushes item onto top of stack.
	container.push_back(item);
}

template<typename Item_Type>
size_t Stack<Item_Type>::Size() const{		// Returns number of items in stack
	return container.size();
}