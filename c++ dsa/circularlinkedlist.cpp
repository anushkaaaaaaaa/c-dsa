#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }
};

void insertAtNode(Node* &tail,int element,int d){
    //assuming that the element is present in the list
    // empty list
    if(tail==NULL){
        Node* newNode =new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        // non empty list
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        //element found-> curr is pointing to element node
        Node* temp = new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deleteNode(Node* &tail,int element){
    //empty list
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        //non empty list
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=element){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

void print (Node* &tail){
    Node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
}

int main(){
    Node* tail=NULL;

    insertAtNode(tail,5,3);
    print(tail);

    insertAtNode(tail,3,6);
    print(tail);

    deleteNode(tail,3);
    print(tail);
    return 0;
}


