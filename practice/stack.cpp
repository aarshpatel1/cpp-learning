#include <iostream>
#define SIZE 100
using namespace std;

class Stack {
  private:
    int top, arr[100];

  public:
    Stack() { top = -1; }

    bool isEmpty() {
        // if (top < 0) {
        //     return true;
        // }
        // return false;

        return top < 0;
    }

    bool isOverflow() {
        // if (top == SIZE - 1) {
        //     return true;
        // }
        // return false;

        return top == SIZE - 1;
    }

    int peek() {
        // if (isEmpty()) {
        //     return 0;
        // }
        // return arr[top];

        // return isEmpty() ? top : arr[top];
        return isEmpty() ? -1 : arr[top];
    }

    int pop() {
        // if (isEmpty()) {
        //     return 0;
        // }
        // return arr[top--];

        // return isEmpty() ? top : arr[top--];
        return isEmpty() ? -1 : arr[top--];
    }

    void push(int value) {
        // if (isOverflow()) {
        //     return;
        // }
        // arr[++top] = value;

        // isOverflow() ? top : arr[++top] = value;
        isOverflow() ? -1 : arr[++top] = value;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;
    cout << "Elements present in stack : ";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    return 0;
}