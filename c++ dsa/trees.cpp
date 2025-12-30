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

Node* buildTree(Node* root){
    cout<< "Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data); 
    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root -> left = buildTree(root -> left); 
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root -> right = buildTree(root -> right);
    return root;
}

void(levelOrderTraversal(Node* root)){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        cout<< temp -> data <<" ";
        q.pop();
        
        if(temp == NULL){ //purana level complete 
            //traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){ //queue still has some child nodes
                q.push(NULL);
            }
        }

        if(temp -> left != NULL){
            q.push(temp -> left);
        }
        
        if(temp -> right){
            q.push(temp -> right);
        }
    }
}


int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}