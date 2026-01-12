#include <iostream>
using namespace std;   
class SinglyLinkedList{
public:
    struct Node{
        int data;
        Node *next;
        Node(int v) : data(v), next(nullptr) {}
    };
    Node *head;
    SinglyLinkedList()  : head(nullptr) {} struct Node{
    int data;
    Node *next;
    Node(int v) : data(v), next(nullptr) {}
    };
}
void push_back(int v){
        Node *n = new Node(v);
        if (!head)
            head = n;
        else
        {
            Node *t = head;
            while (t->next)
                t = t->next;
            t->next = n;
        }
    }
    void print(){
        Node *t = head;
        cout << "List: ";
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }