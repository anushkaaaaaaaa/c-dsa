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
};

//Insertion at Head
Node *insertAtHead(Node *head, int d){
    Node *temp = new Node(d);
    temp -> next = head;
    return temp;
}
//Insertion at Tail
Node *insertAtTail(Node *tail, int d){
    Node *temp = new Node(d);
    tail -> next = temp;
    return temp;
}
//Deletion 
Node *deleteNode(Node *head, int pos){
    Node *temp = head;
    if(pos == 1){
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    return head;
}

void print(Node* &tail){
    Node* temp = tail;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
    
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    print(tail);

    // cout << insertAtHead(head, 12) << endl;
    // cout << insertAtTail(tail, 15) << endl;
}
