#include <bits/stdc++.h> 
using namespace std;
/**********************************************************************

Following is the Binary Tree node structure already written:

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

**********************************************************************/
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int sumAtKthLevel(BinaryTreeNode<int>* root, int k)
{
	// Write your code here.
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(nullptr);

    int sum = 0;
    int count = 0;

    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        // if(front == nullptr && q.empty()) break;

        if(front == nullptr && !q.empty()) {
            cout << "Level Completed\n";
            q.push(nullptr);
        }
        else {
            cout << front->data << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }

}