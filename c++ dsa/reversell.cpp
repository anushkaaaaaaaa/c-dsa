#include <iostream>
using namespace std;

class LinkedListNode
    {
    public:
        int data;
        LinkedListNode* next;
        LinkedListNode(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

void print(LinkedListNode* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
LinkedListNode* reverseLinkedList(LinkedListNode* head) 
{
    LinkedListNode* prev=NULL;
    LinkedListNode* curr=head;
    while(curr!=NULL){
    LinkedListNode* forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
}
}

int main(){
    LinkedListNode* head = new LinkedListNode(10);
    LinkedListNode* newhead = reverseLinkedList(head);
    print(newhead);
}