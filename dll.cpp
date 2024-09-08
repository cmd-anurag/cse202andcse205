#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int val) : data(val), prev(NULL), next(NULL) {};
};

void insertAtTail(Node *&head, int value) {
    Node *createdNode = new Node(value);
    if(head == NULL) {
        head = createdNode;
    }
    else {
        Node *temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        createdNode->prev = temp;
        temp->next = createdNode;
    }
}

void insertAtHead(Node *&head, int value) {
    Node *createdNode = new Node(value);
    if(head == NULL) {
        head = createdNode;
    }
    else {
        createdNode->next = head;
        head->prev = createdNode;
        head = createdNode;
    }
}

void displayLL(Node *head) {
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main() {
    Node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 9);
    // insertAtHead(head, 10);
    insertAtTail(head, 4);
    insertAtTail(head, 7);
    displayLL(head);
}