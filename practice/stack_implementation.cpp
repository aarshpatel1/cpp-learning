#include <iostream>
#define SIZE 100
using namespace std;

class Stack {
  private:
    int top, arr[SIZE];

  public:
    Stack() { top = -1; }

    bool isEmpty() { return top < 0; }
    bool isOverflow() { return top == SIZE - 1; }

    void push(int value) {
        if (isOverflow()) {
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }
};

int main() {

    Stack s;
    // Push elements into the stack

    s.push(10);
    s.push(20);
    s.push(30);

    // Print the top element of the stack
    cout << "Top element is: " << s.peek() << endl;

    // Print all elements in the stack
    cout << "Elements present in stack : ";

    // While the stack is not empty
    while (!s.isEmpty()) {
        // Pop the top element from the stack and print it
        cout << s.pop() << " ";
    }

    return 0;
}