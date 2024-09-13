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

void deleteAtPos(ListNode* &head, int pos) {
    if(pos == 1) {
        ListNode* del = head;
        head = head->next;
        ListNode* current = head;
        while (head->next != nullptr)
        {
            current=current->next;
        }
        current->next = head;        
        delete del;
    }
    else {
        ListNode* current = head;
        ListNode* prev = nullptr;
        for(int i = 1; i < pos; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
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

ListNode* detectLoop(ListNode* head) {
    if(head == nullptr) {
        return nullptr;
    }
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast == nullptr || fast->next == nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return fast;
        }
    }

    return nullptr;
}

int main() {
    ListNode *head = NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 8);
    insertAtTail(head, 7);
    insertAtTail(head, 9);
    displayLL(head);
    cout << detectLoop(head);

}