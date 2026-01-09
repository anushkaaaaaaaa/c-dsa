#include <iostream>
#include <climits>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Global variables to track the maximum sum subtree
int maxSum = INT_MIN;
Node* maxSumSubtreeRoot = nullptr;

// Function to calculate sum of a subtree and track max sum subtree
int findSubtreeSum(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    
    // Calculate sum of left and right subtrees
    int leftSum = findSubtreeSum(root->left);
    int rightSum = findSubtreeSum(root->right);
    
    // Total sum of current subtree
    int currentSum = root->data + leftSum + rightSum;
    
    // Update max sum subtree if current sum is greater
    if (currentSum > maxSum) {
        maxSum = currentSum;
        maxSumSubtreeRoot = root;
    }
    
    return currentSum;
}

// Function to calculate product of all nodes in a subtree
long long calculateProduct(Node* root) {
    if (root == nullptr) {
        return 1;
    }
    
    long long leftProduct = calculateProduct(root->left);
    long long rightProduct = calculateProduct(root->right);
    
    return (long long)root->data * leftProduct * rightProduct;
}

// Function to find product of subtree with maximum sum
long long productOfMaxSumSubtree(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    
    // Reset global variables
    maxSum = INT_MIN;
    maxSumSubtreeRoot = nullptr;
    
    // Find the subtree with maximum sum
    findSubtreeSum(root);
    
    // Calculate and return the product of that subtree
    if (maxSumSubtreeRoot != nullptr) {
        return calculateProduct(maxSumSubtreeRoot);
    }
    
    return 0;
}

// Function to print the subtree (for verification)
void printSubtree(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    printSubtree(root->left);
    printSubtree(root->right);
}

int main() {
    /*
        Example Tree:
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
    root->left->left->left = new Node(7);
    
    // Find the product of subtree with maximum sum
    long long result = productOfMaxSumSubtree(root);
    
    cout << "Maximum Sum of Subtree: " << maxSum << endl;
    cout << "Nodes in Max Sum Subtree (preorder): ";
    printSubtree(maxSumSubtreeRoot);
    cout << endl;
    cout << "Product of Max Sum Subtree: " << result << endl;
    
    cout << "\n--- Another Example ---\n";
    
    /*
        Example Tree 2:
                -1
               /  \
              2    3
             / \
           -4   5
    */
    
    Node* root2 = new Node(-1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(-4);
    root2->left->right = new Node(5);
    
    result = productOfMaxSumSubtree(root2);
    
    cout << "Maximum Sum of Subtree: " << maxSum << endl;
    cout << "Nodes in Max Sum Subtree (preorder): ";
    printSubtree(maxSumSubtreeRoot);
    cout << endl;
    cout << "Product of Max Sum Subtree: " << result << endl;
    
    return 0;
}
