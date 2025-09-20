#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void print(Node *head){
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

// Node *sortList(Node* head){
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;
    
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp->data  == 0){
//             zeroCount++;
//         }
//         else if(temp->data == 1){
//             oneCount++;
//         }
//         else if(temp->data == 2){
//             twoCount++;
//         }
//         temp = temp->next;  
//     }
// temp = head;


// while(temp != NULL){
//     if(zeroCount != 0){
//         temp->data = 0;
//         zeroCount--;
//     }
//     else if(oneCount != 0){
//         temp->data = 1;
//         oneCount--;
//     }
//     else if(twoCount != 0){
//         temp->data = 2;
//         twoCount--;
//     }
//     temp = temp->next;
// }
// return head;
// }

//2nd approach
void insertAtTail(Node* &tail,Node* curr){
    
    tail->next = curr;
    tail = curr;

}
Node* sortList(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head; //store

    //create separate lists for 0s 1s and 2s

    while(curr != NULL){
        int val = curr->data;
        if(val == 0){
            insertAtTail(zeroTail,curr);
        }
        else if(val == 1){
            insertAtTail(oneTail,curr);
        }
        else if(val == 2){
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }
    //merge 3 sublists
    //1s list not empty 
    if(oneHead->next != NULL){
        zeroTail -> next = oneHead -> next;
    }
}
