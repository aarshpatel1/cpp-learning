#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
  public:
    Node *head;
    LinkedList() { head = nullptr; }

    void insert_at_end(int value) {
        Node *temp = new Node(value);
        if (head == nullptr) {
            head = temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }

    void display() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void kgroup(int k) {
        // k = 2;
        Node *prevgroup = nullptr;
        Node *curr = head;
        while (curr != nullptr) {
            int count = 0;
            Node *check = curr;
            while (check != nullptr && count < k) {
                check = check->next;
                count++;
            }

            if (count < k) {
                break;
            }

            Node *prev = nullptr;
            Node *start = curr;

            for (int i = 0; i < k; i++) {
                Node *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if (prevgroup == nullptr) {
                head = prev;
            } else {
                prevgroup->next = prev;
            }
            prevgroup = start;
            prevgroup->next = curr;
            k++;
        }
    }
};

int main() {

    int n;
    cout << "enter n: ";
    cin >> n;

    LinkedList linked_list;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "insert at " << i << ": ";
        cin >> value;
        linked_list.insert_at_end(value);
    }

    linked_list.display();
    cout << "\nenter waves : ";
    int waves;
    cin >> waves;
    linked_list.kgroup(waves);
    // cout << endl;
    linked_list.display();

    return 0;
}
