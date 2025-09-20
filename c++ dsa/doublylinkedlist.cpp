#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertAtHead(Node *&head, Node *&tail, int d)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        return;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        Node *node = new Node(0);
        InsertAtHead(head, tail, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last position
    if (temp->next == NULL)
    {
        InsertAtTail(tail, head, d);
        return;
    }
    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    // deleting first or starting node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next = NULL;
        //memory free
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // cout << getLength(head) << endl;

    InsertAtHead(head, tail, 11);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    InsertAtHead(head, tail, 13);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    InsertAtHead(head, tail, 8);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    InsertAtTail(head, tail, 25);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;
    
    InsertAtPosition(tail, head, 1, 101);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    InsertAtPosition(tail, head, 4, 102);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    deleteNode(4, head, tail);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;
    return 0;
}