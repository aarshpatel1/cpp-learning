#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = nullptr;
    }

    void print() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

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
};

int main() {
    LinkedList linked_list;
    linked_list.insert_at_end(1);
    linked_list.insert_at_end(2);
    linked_list.insert_at_end(3);
    linked_list.insert_at_end(4);
    linked_list.insert_at_end(5);
    linked_list.print();

    return 0;
}
