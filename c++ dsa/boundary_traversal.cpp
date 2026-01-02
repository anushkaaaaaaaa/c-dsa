#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

    void traverseLeftBoundary(TreeNode* root, vector<int>& ans){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)){
            return;
        }
        ans.push_back(root -> data);
        if(root -> left){
            traverseLeftBoundary(root -> left, ans);
        }
        else{
            traverseLeftBoundary(root -> right, ans);
        }

    }
    void traverseLeafNodes(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data);
            return;
        }
        traverseLeafNodes(root -> left, ans);
        traverseLeafNodes(root -> right, ans);
    }
    void traverseRightBoundary(TreeNode* root, vector<int>& ans){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)){
            return;
        }
        if(root -> right){
            traverseRightBoundary(root -> right, ans);
        }
        else{
            traverseRightBoundary(root -> left, ans);
        }
        ans.push_back(root -> data); // add after child visit(reverse)
    }
    vector<int> boundaryTraversal(TreeNode* root){
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root -> data);

        //left boundary
        traverseLeftBoundary(root -> left, ans);

        //leaf nodes
        traverseLeafNodes(root -> left, ans);
        traverseLeafNodes(root -> right, ans);

        //right boundary
        traverseRightBoundary(root -> right, ans);

        return ans;
    }

    

}