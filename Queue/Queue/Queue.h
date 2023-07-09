#include <iostream>
#pragma once
using namespace std;

struct queueNode {
	int data;
	queueNode* nextPtr;
};

class Queue {
private:
	queueNode* frontNode;
	queueNode* backNode;
	int queueCount;

public:
	Queue();
	void enQueue(int d);
	int deQueue();
	int peek();
	bool queueEmpty();
	int getQueueCount();
	void printQueue();
};