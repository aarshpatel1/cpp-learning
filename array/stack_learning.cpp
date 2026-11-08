#include <iostream>
#define SIZE 5
using namespace std;

class Stack {
  private:
    int arr[SIZE], top;

  public:
    Stack() { top = -1; }

    void peek() {
        if (top == -1) {
            cout << "Empty Stack\n";
        }
        cout << "top: " << arr[top] << endl;
    }

    int isfull() {
        if (top == SIZE - 1) {
            return 1;
        }
        return 0;
    }

    void push(int value) {
        if (!isfull()) {
            top++;
            arr[top] = value;
            return;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "stack is underflow";
            return;
        }
        top -= 1;
    }

    bool is_empty() {
        if (top == -1)
            return true;
        return false;
    }
};

int main() {
    Stack stack;
    for (int i = 1; i <= SIZE; i++) {
        stack.push(i);
    }

    while (!stack.is_empty())
    {
        stack.peek();
        stack.pop();
    }
    
    
    return 0;
}