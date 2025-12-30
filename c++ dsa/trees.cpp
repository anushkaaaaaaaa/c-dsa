#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
   
};

Node* buildTree(Node* &root){
    queue<Node*> q;
    cout<< "Enter the data for root: "<<endl;
    int data;
    cin>>data;
    root = new Node(data); 
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter data for inserting in left of "<<temp -> data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout<<"Enter data for inserting in right of "<<temp -> data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }

    // cout<<"Enter data for inserting in left of "<<data<<endl;
    // root -> left = buildTree(root -> left); 
    // cout<<"Enter data for inserting in right of "<<data<<endl;
    // root -> right = buildTree(root -> right);
    // return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){ //purana level complete 
            //traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){ //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<< temp -> data <<" ";
            
            if(temp -> left != NULL){
                q.push(temp -> left);
            }
            
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inorder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<< root -> data <<" ";
    inorder(root -> right);
}
void preorder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    cout<< root -> data <<" ";
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<< root -> data <<" ";
}
int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    buildTree(root);
    levelOrderTraversal(root); 
    // root = buildTree(root);
    // levelOrderTraversal(root);
    // cout<<"Inorder traversal is: "<<endl;
    // inorder(root);    
    // cout<<"Preorder traversal is: "<<endl;    
    // preorder(root);
    // cout<<"Postorder traversal is: "<<endl;    
    // postorder(root);        
    return 0;
}