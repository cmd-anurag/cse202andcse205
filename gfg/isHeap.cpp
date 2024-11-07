#include<bits/stdc++.h>
using namespace std;


// User Function template for C++

// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int countNodes(struct Node* root) {
        if(!root) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
  
    bool isComplete(vector<int> array, int n) {
        for(int i = 0; i < n; ++i) {
            if(array[i] == -1) return false;
        }
        return true;
    }
    
    bool isHeapOrder(struct Node* root) {
        
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        if(root->left && root->left->data > root->data) {
            return false;
        }
        
        if(root->right && root->right->data > root->data) {
            return false;
        }
        
        
        return isHeapOrder(root->left) && isHeapOrder(root->right);
        
        
    }
    
    void treeToArray(struct Node* root, int i, vector<int>& result) {
        if(!root || i >= result.size()) {
            return;
        }
        result[i] = root->data;
        treeToArray(root->left, 2*i+1, result);
        treeToArray(root->right, 2*i+2, result);
    }
  
    bool isHeap(struct Node* tree) {
        // code here
        vector<int> array(100,-1);
        treeToArray(tree, 0, array);
        
        int n = countNodes(tree);
        
        return isComplete(array, n) && isHeapOrder(tree);
       
        
        
    }
};