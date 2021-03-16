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

struct LinkedList{
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void printList(Node* head) {
        struct Node* temp = head;
        while(temp != NULL) {
            cout << temp->data<<" ";
            temp = temp->next;
        }
    }

    Node* reverse_Size(Node* head, int k) {
        if(!head)
            return NULL;
        
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        while(current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if(next != NULL) {
            head->next = reverse_Size(next, k);
        }
        return prev;
    }
};

int main() {
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.push(6);
    ll.push(7);
    ll.push(8);
    ll.push(9);
    ll.push(10);
    ll.printList(ll.head);
    ll.head = ll.reverse_Size(ll.head, 3);
    cout<<endl;
    ll.printList(ll.head);
}