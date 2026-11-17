#include <iostream>
using namespace std;

// Node structure representing each element in the stack
struct Node {
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
  private:
    Node *top;
    int count;

  public:
    // Constructor initializes an empty stack
    Stack() {
        top = nullptr;
        count = 0;
    }

    // Destructor frees all dynamically allocated nodes
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Add an element to the top of the stack (O(1))
    void push(int val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        count++;
    }

    // Remove the top element from the stack (O(1))
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    // Return the top element without removing it (O(1))
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty (O(1))
    bool isEmpty() { return top == nullptr; }

    // Return the current number of elements (O(1))
    int size() { return count; }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl; // Output: 30
    cout << "Stack size: " << s.size() << endl;  // Output: 3

    s.pop();
    cout << "Top after pop: " << s.peek() << endl; // Output: 20

    return 0;
}
