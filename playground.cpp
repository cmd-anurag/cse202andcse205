#include<iostream>
using namespace std;


class Node{
    public:
    int val;
    Node* next;
    Node(int a){
        val =a;
        next = NULL;
    }
};



int main() {
    Node *head = NULL;
    Node* lastNode = NULL;

    int data;
    int size;

    cout << "Enter the size of linked list: ";
    cin >> size;

    for(int i = 0; i < size; ++i) {
        cin >> data;
        Node *newNode = new Node(data);

        if(head == nullptr) {
            head = newNode;
            lastNode = newNode;
        }
        else {
            lastNode->next = newNode;
            lastNode = newNode;
        }
    }

    Node* temp = head;

    while(temp != nullptr) {
        cout <<  temp->val << "--->";
        temp = temp->next;
    }


}