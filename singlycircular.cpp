#include <iostream>

using namespace std;

class ListNode {
    public:
    int data;
    ListNode *next;
    ListNode(int value) : data(value), next(NULL) {};
};

void insertAtTail(ListNode *&head, int value) {
    ListNode* createdNode = new ListNode(value);
    if(head == NULL) {
        head = createdNode;
        createdNode->next = head;
    }
    else {
        ListNode *currentNode = head;
        while (currentNode->next != head) {
            currentNode = currentNode->next;
        }
        currentNode->next = createdNode;
        createdNode->next = head;
    }
}

void displayLL(ListNode *head) {
    ListNode *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main() {
    ListNode *head = NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 8);
    displayLL(head);
}