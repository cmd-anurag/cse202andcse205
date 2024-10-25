#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
};



Node* findMax(Node* root) {
    if(!root) return nullptr;
    Node* temp = root;
    while(temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}

int main()
{
    

    return 0;
}