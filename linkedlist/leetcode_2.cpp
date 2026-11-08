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

    Node(int d) {
        data = d;
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
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void add_two_numbers(Node *l1, Node *l2) {
        Node *temp1 = l1;
        Node *temp2 = l2;
        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr) {
            int value1 = temp1 != nullptr ? temp1->data : 0;
            int value2 = temp2 != nullptr ? temp2->data : 0;
            int addition = value1 + value2 + carry;

            carry = addition / 10;
            addition = addition % 10;
            insert_at_end(addition);

            if (temp1 != nullptr) {
                temp1 = temp1->next;
            }
            if (temp2 != nullptr) {
                temp2 = temp2->next;
            }
        }

        if (carry != 0) {
            insert_at_end(carry);
        }

        display();
    }

    void reverse_linked_list() {
        Node *current = head;
        Node *prev = nullptr;
        Node *forward = nullptr;

        if (head == nullptr) {
            return;
        }

        while (current != nullptr) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }

        head = prev;
    }
};

int main() {

    LinkedList linked_list1;
    // for (int i = 0; i < 7; i++) {
    //     linked_list1.insert_at_end(9);
    // }
    linked_list1.insert_at_end(2);
    linked_list1.insert_at_end(4);
    linked_list1.insert_at_end(3);
    cout << "Linkedlist 1: \n";
    linked_list1.display();
    cout << endl << endl;

    LinkedList linked_list2;
    // for (int i = 0; i < 4; i++) {
    //     linked_list2.insert_at_end(9);
    // }
    linked_list2.insert_at_end(5);
    linked_list2.insert_at_end(6);
    linked_list2.insert_at_end(4);
    cout << "Linkedlist 2: \n";
    linked_list2.display();
    cout << endl << endl;

    LinkedList answer;
    answer.add_two_numbers(linked_list1.head, linked_list2.head);

    return 0;
}

// my submission on leetcode
/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class LinkedList {
  public:
    ListNode *head;

    LinkedList() { head = nullptr; }

    void insert_at_end(int value) {
        ListNode *temp = new ListNode(value);
        if (head == nullptr) {
            head = temp;
            return;
        }
        ListNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        LinkedList linked_list;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int carry = 0;

        while(temp1!=nullptr || temp2!= nullptr){
            int value1 = temp1!=nullptr ? temp1->val : 0;
            int value2 = temp2!=nullptr ? temp2->val : 0;
            int sum = value1 + value2 +carry;
            carry = sum / 10;
            sum = sum %10;
            linked_list.insert_at_end(sum);
            if(temp1 != nullptr) temp1 = temp1->next;
            if(temp2 != nullptr) temp2 = temp2->next;
        }
        if(carry!=0){
            linked_list.insert_at_end(carry);
        }
        return linked_list.head;
    }
};
*/

// best submission
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};
 */