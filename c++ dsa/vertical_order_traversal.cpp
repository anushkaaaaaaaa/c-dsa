#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

// Tree Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to perform vertical order traversal
vector<int> verticalOrderTraversal(Node* root) {
    vector<int> result;
    if (root == NULL) return result;
    
    // Map to store nodes at each horizontal distance
    // Key: horizontal distance, Value: vector of node values
    map<int, vector<int>> nodes;
    
    // Queue for level order traversal
    // Pair: (node, horizontal distance)
    queue<pair<Node*, int>> q;
    
    // Start with root at horizontal distance 0
    q.push({root, 0});
    
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        
        Node* curr = p.first;
        int hd = p.second;
        
        // Add current node to the map
        nodes[hd].push_back(curr->data);
        
        // Add left child with horizontal distance hd-1
        if (curr->left != NULL) {
            q.push({curr->left, hd - 1});
        }
        
        // Add right child with horizontal distance hd+1
        if (curr->right != NULL) {
            q.push({curr->right, hd + 1});
        }
    }
    
    // Extract nodes from map and add to result
    for (auto it : nodes) {
        for (int val : it.second) {
            result.push_back(val);
        }
    }
    
    return result;
}

// Utility function to create a new node
Node* newNode(int data) {
    return new Node(data);
}

int main() {
    // Create a sample binary tree
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    //       /  \
    //      8    9
    
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->right->left = newNode(8);
    root->right->left->right = newNode(9);
    
    cout << "Vertical Order Traversal: ";
    vector<int> result = verticalOrderTraversal(root);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
