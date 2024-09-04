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
}


int main() {
    ListNode *head = NULL;
    ListNode createdNode = ListNode(3);
    head = &createdNode;


}