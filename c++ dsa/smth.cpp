#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

int maxSum = INT_MIN;
Node* maxSumSubtreeRoot = nullptr;

int findSubtreeSum(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = findSubtreeSum(root -> left);
    int rightSum = findSubtreeSum(root -> right);

    int currSum = root -> data + leftSum + rightSum;

    if(currSum > maxSum){
        maxSum = currSum;
        maxSumSubtreeRoot = root;
    }

    return currSum;
}

long long calculateProduct(Node* root){
    if(root == NULL){
        return 1;
    }
    long long leftProd = calculateProduct(root -> left);
    long long rightProd = calculateProduct(root -> right);

    return (long long)root -> data * leftProd * rightProd;
    
}
int productOfMaxSumSubtree(Node* root){
    if(root == NULL){
        return 0;
    }
    maxSum = INT_MIN;
    maxSumSubtreeRoot = nullptr;

    findSubtreeSum(root);

    if(maxSumSubtreeRoot != nullptr){
        return calculateProduct(maxSumSubtreeRoot);
    }

    return 0;
}
