#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "\nQUEUE OVERFLOW\n";
            return;
        }
        if (front == -1) front = 0; 
        rear++;
        arr[rear] = x;
        cout << "\n" << x << " enqueued into queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQUEUE UNDERFLOW\n";
            return;
        }
        cout << "\n" << arr[front] << " dequeued from queue.\n";
        front++;
        if (front > rear) { 
            front = rear = -1;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nQUEUE IS EMPTY\n";
            return;
        }
        cout << "\nFront element is: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQUEUE IS EMPTY\n";
            return;
        }
        cout << "\nQueue: \n";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "\nExiting program.\n";
            break;

        default:
            cout << "\nInvalid Choice\n";
        }
    } while (choice != 5);

    return 0;
}

