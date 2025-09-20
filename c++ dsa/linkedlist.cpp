#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
//destructor declaration
~Node(){
    int value = this -> data;
    //memory free
    if(this -> next != NULL){
        delete next;
        this -> next = NULL;
    }
    cout<<"Memory is free for node with data "<<value<<endl;
};

void InsertAtHead(Node* &head,int d){
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
};

void InsertAtTail(Node* &tail,int d){
    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
            
void print(Node* &tail){
    Node* temp = tail;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
    
}
void InsertAtPosition(Node* &tail,Node* &head,int position,int d){
    //inserting at starting position
    if(position == 1){
        Node* node = new Node(0);
        node -> InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    //inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail,d);
        return;
    }
    //creating a node for d
    Node* nodeToInsert=new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position,Node* &head,Node* &tail){
    //deleting first or starting node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

//Sort the linked list




int main(){
    Node* node1=new Node(10);
    Node* node2=new Node(20);
    
    cout<<node1 -> data<<endl;
    cout<<node1 -> next<<endl;


    //head pointed to node1

    Node* head = node1;
    Node* tail = node2;
    print(head);
    node1 -> InsertAtHead(head,12);
    print(head);
    InsertAtTail(node2,15);
    print(tail);
    return 0;

};