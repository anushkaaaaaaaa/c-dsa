#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Breadth First Traversal (Level Order Traversal)
void bfs(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    cout << "BFS Traversal: ";
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        cout << current->data << " ";
        
        // Enqueue left child
        if (current->left != nullptr) {
            q.push(current->left);
        }
        
        // Enqueue right child
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Level Order Traversal with levels printed separately
void bfsLevelWise(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    cout << "BFS Level-wise Traversal:" << endl;
    int level = 0;
    
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "Level " << level << ": ";
        
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
        level++;
    }
}

int main() {
    /*
        Creating the following binary tree:
                1
               / \
              2   3
             / \   \
            4   5   6
               /
              7
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    
    // Simple BFS traversal
    bfs(root);
    
    cout << endl;
    
    // Level-wise BFS traversal
    bfsLevelWise(root);
    
    return 0;
}
