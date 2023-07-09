#include "Queue.h"

Queue::Queue() { 
	frontNode = nullptr;	// set nodes to null and queueCount to zero
	backNode = nullptr;
	queueCount = 0;
}
void Queue::enQueue(int d){
    queueNode* temp = new queueNode; // create node
    temp->data = d;                 // set data to argument passed
    temp->nextPtr = nullptr;
    if (frontNode == nullptr) { // add to empty list
        frontNode = temp;
        backNode = temp;
        queueCount++;
    }
    else {  // add to end of list
        backNode->nextPtr = temp;
        backNode = temp;
        queueCount++;
    }
}
int Queue::deQueue(){
    
    if (frontNode == nullptr) {  // check for empty list
        cout << "Queue is empty.\n"; // if queue is empty, prints message and returns -1
        return -1;
    }
    else {                      // take from front of list
        queueNode* delNode = frontNode;
        queueNode* tempData = new queueNode;
        tempData->data = frontNode->data;
        frontNode = frontNode->nextPtr;
        delete delNode;
        delNode = nullptr;
        queueCount--;
        return tempData->data;
    }
}
int Queue::peek(){
    
    if (frontNode == nullptr) {  // check if list is empty
        cout << "Queue is empty.\n";    // if queue is empty prints message and returns -1
        return -1;
    }
    else {
        return frontNode->data; // return contents of front of list
    }
}
bool Queue::queueEmpty(){
    if (frontNode == nullptr) {     // if frontNode is null return true that queue is empty
        return true;
    }
    return false;                   // otherwise return false
}
int Queue::getQueueCount() {
    return queueCount;              // returns queueCount
}
void Queue::printQueue() {
    queueNode* tempNode = frontNode;
    while (tempNode != nullptr) {       // traverses through list and prints contents
        if (tempNode->nextPtr != nullptr) {
            cout << tempNode->data << ", ";
        }
        else {
            cout << tempNode->data << endl;
        }
        tempNode = tempNode->nextPtr;
        
    }
}