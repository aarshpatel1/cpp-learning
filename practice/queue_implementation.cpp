#include <iostream>
#define SIZE 100
using namespace std;

class Queue {
  private:
    int front, rear, arr[SIZE];

  public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return rear == SIZE - 1; }

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

    void enqueue(int value) {
        if (isFull()) {
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int temp = arr[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return temp;
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // Enqueueing elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Displaying status of the queue after enqueuing
    cout << "\nAfter Enqueueing:" << endl;

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.display();

    // Enqueueing more elements
    q.enqueue(4);
    q.enqueue(5);

    // Displaying the updated queue
    q.display();

    // Enqueueing one more element to demonstrate overflow
    // condition
    q.enqueue(6);

    // Dequeueing elements
    cout << "\nDequeueing elements:" << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    // Displaying status of the queue after dequeueing
    cout << "\nAfter Dequeueing:" << endl;

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.display();

    return 0;
}