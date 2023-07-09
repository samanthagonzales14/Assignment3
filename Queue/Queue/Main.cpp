#include "Queue.h"

int main() {
	Queue myQueue;
	int userChoice;
	int queueVal;
	while (true) {
		cout << "\n       Main Menu:\n\n";
		cout << "Press 1: Add Value to Queue\n";
		cout << "Press 2: Remove Front Value from Queue\n";
		cout << "Press 3: View Front Value in Queue\n";
		cout << "Press 4: Check if Queue is Empty\n";
		cout << "Press 5: Get Length of Queue\n";
		cout << "Press 6: Display Queue\n";
		cout << "Press 7: Exit\n\n";

		cout << "Enter choice: ";
		cin >> userChoice;

		if (userChoice == 7) {
			break;
		}

		switch (userChoice) {
		case 1:
			cout << "\nEnter a value to add to queue: ";
			cin >> queueVal;
			myQueue.enQueue(queueVal);
			break;
		case 2:
			cout << myQueue.deQueue() << endl;
			break;
		case 3:
			cout << myQueue.peek();
			break;
		case 4:
			if (myQueue.queueEmpty() == 0) {
				cout << "\nQueue is NOT empty.\n";
			}
			else if (myQueue.queueEmpty() == 1) {
				cout << "\nQueue is empty.\n";
			}
			break;
		case 5:
			cout << "\nThe length of the queue is: " << myQueue.getQueueCount() << endl;
			break;
		case 6:
			cout << "\nCurrent Queue:\n";
			myQueue.printQueue();
			break;
		default:
			cout << "Invalid choice\n";
		}
	}
	return 0;
}