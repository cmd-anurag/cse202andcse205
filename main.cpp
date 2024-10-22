#include<iostream>
#include<queue>

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

queue<Node *> q;


void printRightView(Node* root) {
    if(!root) return;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            Node* current = q.front();
            q.pop();
            if(i == size -1) {
                cout << current->data << " ";
            }
            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
    }
}

bool getPath(Node *root, int key, vector<int> &path) {

    if(!root) {
        return false;
    }

    path.push_back(root->data);
    if(root->data == key) return true;

    if(getPath(root->left, key, path) || getPath(root->left, key, path)) {
        return true;
    }
    path.pop_back();
    return false;
}


int lowestCommonAncestor(Node* root, int key1, int key2) {
    vector<int> key1path;
    vector<int> key2path;

    if(!getPath(root, key1, key1path) || !getPath(root, key2, key2path)) {
        return -1;
    }

}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = arrayToBinaryTree(arr, n);

    cout << findHeight(root);
    printRightView(root);

    return 0;
}