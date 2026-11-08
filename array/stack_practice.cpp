#include <iostream>
#define SIZE 100
using namespace std;

class Stack {
  private:
    int top, arr[SIZE];

  public:
    Stack() { top = -1; }

    bool is_empty() { return (top < 0); }

    bool is_full() { return (top == SIZE - 1); }

    void push(int value) {
        if (is_full()) {
            cout << "Stack is full\n";
            return;
        }
        top++;
        arr[top] = value;
        cout << "pushed: " << value << endl;
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return 0;
        }
        return arr[top--];
    }

    int peek() {
        if (is_empty()) {
            return 0;
        }
        return arr[top];
    }
};

int main() {

    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "top: " << stack.peek() << endl;

    cout << "elements deleted: ";
    while (!stack.is_empty()) {
        cout << stack.pop() << " ";
    }

    return 0;
}