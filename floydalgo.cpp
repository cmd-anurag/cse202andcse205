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
    ListNode *head = createLinkedList();
    displayLL(head);
    cout << detectLoop(head);
}