#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void insert_at_head(int value)
    {
        Node *temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
            return;
        }

        temp->next = head;
        head = temp;
    }

    void insert_at_tail(int value)
    {
        Node *temp = new Node(value);
        Node *current = head;

        if (head == NULL)
        {
            head = temp;
            return;
        }

        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }

    void print()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList list;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value: ";
        int value;
        cin >> value;
        list.insert_at_tail(value);
    }

    list.print();

    return 0;
}