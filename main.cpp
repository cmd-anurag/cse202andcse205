#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* arrayToBinaryTree(int arr[], int n, int i = 0) {
    if (i >= n || arr[i] == -1) return NULL;

    Node* root = new Node(arr[i]);
    root->left = arrayToBinaryTree(arr, n, 2 * i + 1);
    root->right = arrayToBinaryTree(arr, n, 2 * i + 2);

    return root;
}

void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int findHeight(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = arrayToBinaryTree(arr, n);

   cout << findHeight(root);

    return 0;
}