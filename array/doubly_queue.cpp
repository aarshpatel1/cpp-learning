#include <iostream>
#define SIZE 100
using namespace std;

class Deque {
  private:
    int front, rear, arr[SIZE];

  public:
    Deque() { front = rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    void insertAtFront(int value) {
        if (isFull()) {
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        arr[front] = value;
    }

    void insertAtRear(int value) {
        if (isFull()) {
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    int deleteAtFront() {
        if (isEmpty()) {
            return -1;
        }
        int temp = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        return temp;
    }

    int deleteAtRear() {
        if (isEmpty()) {
            return -1;
        }
        int temp = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
        return temp;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;
    deque.insertAtFront(10);
    deque.insertAtRear(20);
    deque.insertAtFront(5);
    deque.insertAtRear(30);

    // Display the Deque after pushes
    cout << "Deque after pushes: ";
    deque.display();

    // Get and display the front and rear elements
    cout << "Front element: " << deque.getFront() << endl;
    cout << "Rear element: " << deque.getRear() << endl;

    // Pop elements from the front and back
    deque.deleteAtFront();
    deque.deleteAtRear();

    // Display the Deque after pops
    cout << "Deque after pops: ";
    deque.display();
    return 0;
}