#include <iostream>

using namespace std;

class ListNode {
    public:
    int data;
    ListNode *next;
    ListNode(int value) : data(value), next(NULL) {};
};

ListNode* createLinkedList() {
    int n;
    cout << "Enter the length of linked list: ";
    cin >> n;
    ListNode *head = NULL;
    ListNode *temp = NULL;
    int data;
    for(int i = 0; i < n; ++i) {
        cout << "Enter the data for node " << i+1 << endl;
        cin >> data;

        ListNode *newNode = new ListNode(data);

        if(head == NULL) {
            head = newNode;
        }
        else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

void displayLL(ListNode *head) {
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void insertAtTail(ListNode* &head, int data) {
    ListNode *createdNode = new ListNode(data);
    if(head == NULL) {
        head = createdNode;
        return;
    }

    ListNode *currentNode = head;

    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = createdNode;
}

void insertAtStart(ListNode * &head, int value) {
    ListNode *createdNode = new ListNode(value);

    if(head == NULL) {
        head = createdNode;
        return;
    }
    createdNode->next = head;
    head = createdNode;
}

bool searchLL(ListNode *head, int key) {
    ListNode* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    ListNode *head = NULL;
    // head = createLinkedList();
    // displayLL(head);
    
    insertAtStart(head, 12);
    insertAtStart(head, 13);
    insertAtStart(head, 14);
    displayLL(head);
    cout << searchLL(head, 1);
}