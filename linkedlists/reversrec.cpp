#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void reverseList(struct Node* p) {
        if(p->next == NULL) {
            head = p;
            return;
        }
        reverseList(p->next);
        struct Node* q = p->next;
        q->next = p;
        p->next = NULL;
    }

    void printList() {
        struct Node* temp = head;
        while(temp != NULL) {
            cout << temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.printList();
    ll.reverseList(ll.head);
    cout<<endl;
    ll.printList();
}