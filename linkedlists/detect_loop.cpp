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

    void createLoop(Node* head, int k) {
        Node *temp = head, *last = head;
        int count = 1;
        if(k == 0) {
            return;
        }
        while(temp!= NULL && count < k) {
            temp = temp->next;
            count++;
        }
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }

    int detectLoop(Node* head) {
        Node *slow_p = head, *fast_p = head;
        while(slow_p && fast_p && fast_p->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if(slow_p == fast_p) {
                return 1;
            }
        }
        return 0;
    }
};

int main() {
    int data;
    LinkedList ll;
    while(1) {
        cin>>data;
        if(data < 0)
            break;
        ll.push(data);
    }
    int x;
    cin>>x;
    ll.printList(ll.head);
    ll.createLoop(ll.head, x);
    if(ll.detectLoop(ll.head)) {
        cout<<"TRUE"<<endl;
    } else {
        cout<<"FALSE"<<endl;
    }
    cout<<endl;
}