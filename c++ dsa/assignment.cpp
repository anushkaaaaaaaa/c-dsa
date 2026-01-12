#include <bits/stdc++.h>
using namespace std;

// 2. Insert and delete element in an array 
void array_insert_delete(){
     vector<int> a;
    int n;
    cout << "\nEnter number of initial elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << "Array: ";
    for (int v : a)
        cout << v << " ";
    cout << "\nInsert value and position (0-based): ";
    int val, pos;
    cin >> val >> pos;
    if (pos < 0)
        pos = 0;
    if (pos > (int)a.size())
        pos = a.size();
    a.insert(a.begin() + pos, val);
    cout << "After insertion: ";
    for (int v : a)
        cout << v << " ";
    cout << "\nDelete position (0-based): ";
    cin >> pos;
    if (pos >= 0 && pos < (int)a.size())
        a.erase(a.begin() + pos);
    cout << "After deletion: ";
    for (int v : a)
        cout << v << " ";
    cout << "\n";
}








/* ---------- 7-10 : Singly linked list ---------- */
struct Node{
    int data;
    Node *next;
    Node(int v) : data(v), next(nullptr) {}
};
class SinglyLinkedList{
public:
    Node *head;
    SinglyLinkedList() : head(nullptr) {}

    // 8 insert node at pos and delete node by pos
    void insert_at(int pos, int val){
        Node *n = new Node(val);
        if (pos <= 0 || !head)
        {
            n->next = head;
            head = n;
            return;
        }
        Node *t = head;
        int i = 0;
        while (t->next && i < pos - 1)
        {
            t = t->next;
            i++;
        }
        n->next = t->next;
        t->next = n;
    }
    void delete_at(int pos){
        if (!head)
            return;
        if (pos <= 0){
            Node *tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        Node *t = head;
        int i = 0;
        while (t->next && i < pos - 1){
            t = t->next;
            i++;
        }
        if (t->next){
            Node *tmp = t->next;
            t->next = tmp->next;
            delete tmp;
        }
    }
    // 9 print in reverse without disturbing list -> recursion
    void print_reverse(Node *p)
    {
        if (!p)
            return;
        print_reverse(p->next);
        cout << p->data << " ";
    }
    // 10 reverse linked list (in-place)
    void reverse_list()
    {
        Node *prev = nullptr;
        Node *cur = head;
        while (cur)
        {
            Node *nx = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nx;
        }
        head = prev;
    }
    // destructor to free nodes
    ~SinglyLinkedList()
    {
        Node *t = head;
        while (t)
        {
            Node *nx = t->next;
            delete t;
            t = nx;
        }
    }
};

/* ---------- 11 : Add two polynomials using linked lists ---------- */
struct Term{
    int coeff, pow;
    Term *next;
    Term(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};
class Polynomial{
public:
    Term *head;
    Polynomial() : head(nullptr) {}
    void append(int coeff, int pow){
        Term *t = new Term(coeff, pow);
        if (!head)
            head = t;
        else{
        Term *r = head;
            while (r->next)
                r = r->next;
            r->next = t;
        }
    }
    static Polynomial add(Polynomial &A, Polynomial &B){
        Polynomial R;
        Term *a = A.head;
        Term *b = B.head;
        while (a && b){
            if (a->pow == b->pow){
                int s = a->coeff + b->coeff;
                if (s)
                    R.append(s, a->pow);
                a = a->next;
                b = b->next;
            }
            else if (a->pow > b->pow){
                R.append(a->coeff, a->pow);
                a = a->next;
            }
            else{
                R.append(b->coeff, b->pow);
                b = b->next;
            }
        }
        while (a){
            R.append(a->coeff, a->pow);
            a = a->next;
        }
        while (b){
            R.append(b->coeff, b->pow);
            b = b->next;
        }
        return R;
    }
    void print()
    {
        Term *t = head;
        if (!t)
        {
            cout << "0\n";
            return;
        }
        bool first = true;
        while (t)
        {
            if (!first && t->coeff > 0)
                cout << "+";
            cout << t->coeff << "x^" << t->pow << " ";
            first = false;
            t = t->next;
        }
        cout << "\n";
    }
    ~Polynomial()
    {
        Term *t = head;
        while (t)
        {
            Term *n = t->next;
            delete t;
            t = n;
        }
    }
};

/* ---------- 12 : Doubly linked list ---------- */

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
public:
    DNode *head;
    DoublyLinkedList() : head(nullptr) {}
    void push_back(int v)
    {
        DNode *n = new DNode(v);
        if (!head)
            head = n;
        else
        {
            DNode *t = head;
            while (t->next)
                t = t->next;
            t->next = n;
            n->prev = t;
        }
    }
    void insert_at(int pos, int v)
    {
        DNode *n = new DNode(v);
        if (!head || pos <= 0)
        {
            n->next = head;
            if (head)
                head->prev = n;
            head = n;
            return;
        }
        DNode *t = head;
        int i = 0;
        while (t->next && i < pos - 1)
        {
            t = t->next;
            i++;
        }
        n->next = t->next;
        if (t->next)
            t->next->prev = n;
        t->next = n;
        n->prev = t;
    }
    void delete_at(int pos)
    {
        if (!head)
            return;
        if (pos <= 0)
        {
            DNode *tmp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete tmp;
            return;
        }
        DNode *t = head;
        int i = 0;
        while (t->next && i < pos)
        {
            t = t->next;
            i++;
        }
        if (i < pos)
            return;
        DNode *p = t->prev;
        p->next = t->next;
        if (t->next)
            t->next->prev = p;
        delete t;
    }
    void print()
    {
        DNode *t = head;
        cout << "DLL: ";
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
    ~DoublyLinkedList()
    {
        DNode *t = head;
        while (t)
        {
            DNode *nx = t->next;
            delete t;
            t = nx;
        }
    }
};

/* ---------- 13-14 : Stack using array and linked list ---------- */

class StackArray
{
    vector<int> st;
    int cap;

public:
    StackArray(int c = 100) : cap(c) { st.reserve(c); }
    void push(int x)
    {
        if ((int)st.size() >= cap)
        {
            cout << "Overflow\n";
            return;
        }
        st.push_back(x);
    }
    void pop()
    {
        if (st.empty())
        {
            cout << "Empty\n";
        }
        else
            st.pop_back();
    }
    int top()
    {
        if (st.empty())
            return INT_MIN;
        return st.back();
    }
    bool empty() { return st.empty(); }
    void print()
    {
        cout << "Stack (top->bottom): ";
        for (int i = st.size() - 1; i >= 0; i--)
            cout << st[i] << " ";
        cout << "\n";
    }
};

class StackLinked
{
    Node *topNode;

public:
    StackLinked() : topNode(nullptr) {}
    void push(int x)
    {
        Node *n = new Node(x);
        n->next = topNode;
        topNode = n;
    }
    void pop()
    {
        if (!topNode)
            cout << "Empty\n";
        else
        {
            Node *t = topNode;
            topNode = topNode->next;
            delete t;
        }
    }
    int top()
    {
        if (!topNode)
            return INT_MIN;
        return topNode->data;
    }
    bool empty() { return topNode == nullptr; }
    void print()
    {
        cout << "StackLinked (top->bottom): ";
        Node *t = topNode;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
    ~StackLinked()
    {
        while (topNode)
        {
            Node *t = topNode;
            topNode = topNode->next;
            delete t;
        }
    }
};

/* ---------- 15-16 : Queue using array and linked list ---------- */

class QueueArray
{
    vector<int> arr;
    int headIdx = 0;

public:
    QueueArray()
    {
        arr.clear();
        headIdx = 0;
    }
    void enqueue(int x) { arr.push_back(x); }
    void dequeue()
    {
        if (headIdx >= (int)arr.size())
        {
            cout << "Empty\n";
        }
        else
            headIdx++;
    }
    int front()
    {
        if (headIdx >= (int)arr.size())
            return INT_MIN;
        return arr[headIdx];
    }
    bool empty() { return headIdx >= (int)arr.size(); }
    void print()
    {
        cout << "Queue: ";
        for (int i = headIdx; i < (int)arr.size(); i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

class QueueLinked
{
    Node *head;
    Node *tail;

public:
    QueueLinked() : head(nullptr), tail(nullptr) {}
    void enqueue(int x)
    {
        Node *n = new Node(x);
        if (!tail)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }
    void dequeue()
    {
        if (!head)
        {
            cout << "Empty\n";
        }
        else
        {
            Node *t = head;
            head = head->next;
            if (!head)
                tail = nullptr;
            delete t;
        }
    }
    int front()
    {
        if (!head)
            return INT_MIN;
        return head->data;
    }
    bool empty() { return head == nullptr; }
    void print()
    {
        cout << "QueueLinked: ";
        Node *t = head;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
    ~QueueLinked()
    {
        while (head)
        {
            Node *t = head;
            head = head->next;
            delete t;
        }
    }
};

/* ---------- 17 : Circular queue (array implementation) ---------- */

class CircularQueue
{
    vector<int> data;
    int head, tail, capacity;
    bool fullFlag;

public:
    CircularQueue(int cap = 5) : data(cap), head(0), tail(0), capacity(cap), fullFlag(false) {}
    bool empty() { return (!fullFlag && head == tail); }
    bool full() { return fullFlag; }
    bool enqueue(int x)
    {
        if (full())
            return false;
        data[tail] = x;
        tail = (tail + 1) % capacity;
        if (tail == head)
            fullFlag = true;
        return true;
    }
    bool dequeue()
    {
        if (empty())
            return false;
        head = (head + 1) % capacity;
        fullFlag = false;
        return true;
    }
    int front()
    {
        if (empty())
            return INT_MIN;
        return data[head];
    }
    void print()
    {
        cout << "CircularQueue: ";
        if (empty())
        {
            cout << "empty\n";
            return;
        }
        int i = head;
        while (true)
        {
            cout << data[i] << " ";
            i = (i + 1) % capacity;
            if (i == tail && !fullFlag)
                break;
            if (i == head && fullFlag)
            { // printed full cycle
                break;
            }
            if (i == tail && fullFlag)
                break;
            if (i == tail && !fullFlag)
                break;
        }
        cout << "\n";
    }
};

/* ---------- 18 : Priority queue using linked list ---------- */
struct PNode
{
    int val;
    int pr;
    PNode *next;
    PNode(int v, int p) : val(v), pr(p), next(nullptr) {}
};

class PriorityQueueLinked
{
    PNode *head;

public:
    PriorityQueueLinked() : head(nullptr) {}
    void push(int val, int pr)
    {
        PNode *n = new PNode(val, pr);
        if (!head || pr < head->pr)
        {
            n->next = head;
            head = n;
            return;
        }
        PNode *t = head;
        while (t->next && t->next->pr <= pr)
            t = t->next;
        n->next = t->next;
        t->next = n;
    }
    void pop()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        PNode *t = head;
        head = head->next;
        delete t;
    }
    int top()
    {
        if (!head)
            return INT_MIN;
        return head->val;
    }
    bool empty() { return head == nullptr; }
    void print()
    {
        cout << "PriorityQueue: ";
        PNode *t = head;
        while (t)
        {
            cout << "(v=" << t->val << ",p=" << t->pr << ") ";
            t = t->next;
        }
        cout << "\n";
    }
    ~PriorityQueueLinked()
    {
        while (head)
        {
            PNode *t = head;
            head = head->next;
            delete t;
        }
    }
};

/* ---------- 19 : Double-ended queue using linked list (deque) ---------- */

class DequeLinked
{
    DNode *head;
    DNode *tail;

public:
    DequeLinked() : head(nullptr), tail(nullptr) {}
    void push_front(int v)
    {
        DNode *n = new DNode(v);
        if (!head)
        {
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }
    void push_back(int v)
    {
        DNode *n = new DNode(v);
        if (!tail)
        {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    void pop_front()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        DNode *t = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete t;
    }
    void pop_back()
    {
        if (!tail)
        {
            cout << "Empty\n";
            return;
        }
        DNode *t = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete t;
    }
/*************  ✨ Windsurf Command 🌟  *************/
    /// Prints the contents of the deque.
    ///
    /// This function prints the contents of the deque from front to back.
    ///
    /// @remark This function does not modify the deque.
    ///
    /// @return void
    ///
    /// @throws std::runtime_error If the deque is empty.

    void print()
    {
        cout << "Deque: ";
        DNode *t = head;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
/*******  5ad25d1f-65d5-4562-b402-978f19aaf723  *******/
    }
    ~DequeLinked()
    {
        while (head)
        {
            DNode *t = head;
            head = head->next;
            delete t;
        }
    }
};

/* ---------- 20 : Binary tree + traversals ---------- */

struct BNode
{
    int val;
    BNode *left;
    BNode *right;
    BNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    BNode *root;
    BinaryTree() : root(nullptr) {}
    // simple insert as level-order to create a binary tree from vector
    void build_from_vector(const vector<int> &v)
    {
        if (v.empty())
        {
            root = nullptr;
            return;
        }
        root = new BNode(v[0]);
        queue<BNode *> q;
        q.push(root);
        int i = 1;
        while (i < (int)v.size())
        {
            BNode *cur = q.front();
            q.pop();
            if (i < (int)v.size())
            {
                cur->left = new BNode(v[i++]);
                q.push(cur->left);
            }
            if (i < (int)v.size())
            {
                cur->right = new BNode(v[i++]);
                q.push(cur->right);
            }
        }
    }
    void preorder(BNode *p)
    {
        if (!p)
            return;
        cout << p->val << " ";
        preorder(p->left);
        preorder(p->right);
    }
    void inorder(BNode *p)
    {
        if (!p)
            return;
        inorder(p->left);
        cout << p->val << " ";
        inorder(p->right);
    }
    void postorder(BNode *p)
    {
        if (!p)
            return;
        postorder(p->left);
        postorder(p->right);
        cout << p->val << " ";
    }
    ~BinaryTree()
    {
        // cleanup
        if (!root)
            return;
        queue<BNode *> q;
        q.push(root);
        while (!q.empty())
        {
            BNode *t = q.front();
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            delete t;
        }
    }
};

/* ---------- 21 : Binary Search Tree (BST) ---------- */

class BST
{
public:
    BNode *root;
    BST() : root(nullptr) {}
    void insert(int v) { root = insertRec(root, v); }
    BNode *insertRec(BNode *node, int v)
    {
        if (!node)
            return new BNode(v);
        if (v < node->val)
            node->left = insertRec(node->left, v);
        else
            node->right = insertRec(node->right, v);
        return node;
    }
    void inorder()
    {
        inorderRec(root);
        cout << "\n";
    }
    void inorderRec(BNode *node)
    {
        if (!node)
            return;
        inorderRec(node->left);
        cout << node->val << " ";
        inorderRec(node->right);
    }
    ~BST()
    { // simple postorder deletion
        // reuse queueless deletion
        delete_subtree(root);
    }
    void delete_subtree(BNode *p)
    {
        if (!p)
            return;
        delete_subtree(p->left);
        delete_subtree(p->right);
        delete p;
    }
};

/* ---------- Menu & main ---------- */

void print_menu()
{
    cout << "\nChoose task to run:\n";
    cout << "2 Array insert/delete\n3 Search in array\n4 Sort array\n5 Merge two sorted arrays\n6 Store marks (2D array)\n";
    cout << "7 Create a linked list (and show)\n8 Insert/delete in linked list\n9 Print linked list in reverse\n10 Reverse linked list\n11 Add two polynomials\n12 Doubly linked list operations\n";
    cout << "13 Stack (array)\n14 Stack (linked list)\n15 Queue (array)\n16 Queue (linked list)\n17 Circular queue (array)\n18 Priority queue (linked list)\n19 Deque (double-ended queue using linked list)\n";
    cout << "20 Binary tree traversals\n21 Binary Search Tree (construct + inorder)\n0 Exit\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        print_menu();
        int choice;
        cout << "Enter choice: ";
        if (!(cin >> choice))
            return 0;
        if (choice == 0)
            break;
        switch (choice)
        {
        case 2:
            array_insert_delete();
            break;
        case 3:
            array_search();
            break;
        case 4:
            array_sorting();
            break;
        case 5:
            merge_two_sorted();
            break;
        case 6:
            store_marks_2d();
            break;
        case 7:
        {
            SinglyLinkedList L;
            cout << "Enter number of nodes and values: ";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                L.push_back(x);
            }
            L.print();
            break;
        }
        case 8:
        {
            SinglyLinkedList L;
            cout << "Build list: enter n then n values: ";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                L.push_back(x);
            }
            cout << "List before: ";
            L.print();
            cout << "Insert pos val: ";
            int pos, val;
            cin >> pos >> val;
            L.insert_at(pos, val);
            cout << "After insert: ";
            L.print();
            cout << "Delete pos: ";
            cin >> pos;
            L.delete_at(pos);
            cout << "After delete: ";
            L.print();
            break;
        }
        case 9:
        {
            SinglyLinkedList L;
            int n;
            cout << "n: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                L.push_back(x);
            }
            cout << "Reverse printed: ";
            L.print_reverse(L.head);
            cout << "\nList preserved: ";
            L.print();
            break;
        }
        case 10:
        {
            SinglyLinkedList L;
            int n;
            cout << "n: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                L.push_back(x);
            }
            cout << "Before: ";
            L.print();
            L.reverse_list();
            cout << "After reverse: ";
            L.print();
            break;
        }
        case 11:
        {
            Polynomial A, B;
            int na;
            cout << "Terms in A: ";
            cin >> na;
            cout << "Enter coeff pow pairs in descending pow:\n";
            for (int i = 0; i < na; i++)
            {
                int c, p;
                cin >> c >> p;
                A.append(c, p);
            }
            int nb;
            cout << "Terms in B: ";
            cin >> nb;
            for (int i = 0; i < nb; i++)
            {
                int c, p;
                cin >> c >> p;
                B.append(c, p);
            }
            cout << "A: ";
            A.print();
            cout << "B: ";
            B.print();
            Polynomial R = Polynomial::add(A, B);
            cout << "Sum: ";
            R.print();
            break;
        }
        case 12:
        {
            DoublyLinkedList D;
            int n;
            cout << "n: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                D.push_back(x);
            }
            D.print();
            cout << "Insert pos val: ";
            int pos, val;
            cin >> pos >> val;
            D.insert_at(pos, val);
            D.print();
            cout << "Delete pos: ";
            cin >> pos;
            D.delete_at(pos);
            D.print();
            break;
        }
        case 13:
        {
            StackArray S(100);
            cout << "Push some values (enter count then values): ";
            int k;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                S.push(x);
            }
            S.print();
            cout << "Pop count: ";
            cin >> k;
            for (int i = 0; i < k; i++)
                S.pop();
            S.print();
            break;
        }
        case 14:
        {
            StackLinked S;
            int k;
            cout << "Push count then values: ";
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                S.push(x);
            }
            S.print();
            cout << "Pop count: ";
            cin >> k;
            for (int i = 0; i < k; i++)
                S.pop();
            S.print();
            break;
        }
        case 15:
        {
            QueueArray Q;
            int k;
            cout << "Enqueue count & values: ";
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                Q.enqueue(x);
            }
            Q.print();
            cout << "Dequeue count: ";
            cin >> k;
            for (int i = 0; i < k; i++)
                Q.dequeue();
            Q.print();
            break;
        }
        case 16:
        {
            QueueLinked Q;
            int k;
            cout << "Enqueue count & values: ";
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                Q.enqueue(x);
            }
            Q.print();
            cout << "Dequeue count: ";
            cin >> k;
            for (int i = 0; i < k; i++)
                Q.dequeue();
            Q.print();
            break;
        }
        case 17:
        {
            cout << "Capacity for circular queue: ";
            int cap;
            cin >> cap;
            CircularQueue C(cap);
            cout << "Enqueue count & values: ";
            int k;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                if (!C.enqueue(x))
                    cout << "Queue full, cannot enqueue " << x << "\n";
            }
            C.print();
            cout << "Dequeue count: ";
            cin >> k;
            for (int i = 0; i < k; i++)
                if (!C.dequeue())
                    cout << "Cannot dequeue\n";
            C.print();
            break;
        }
        case 18:
        {
            PriorityQueueLinked P;
            cout << "Enter number of items to push: ";
            int k;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int v, p;
                cin >> v >> p;
                P.push(v, p);
            }
            P.print();
            cout << "Pop count: ";
            cin >> k;
            for (int i = 0; i < k; i++)
                P.pop();
            P.print();
            break;
        }
        case 19:
        {
            DequeLinked D;
            cout << "Operations: Enter k and then k operations: (1 push_front v; 2 push_back v; 3 pop_front; 4 pop_back)\n";
            int k;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int op;
                cin >> op;
                if (op == 1)
                {
                    int v;
                    cin >> v;
                    D.push_front(v);
                }
                else if (op == 2)
                {
                    int v;
                    cin >> v;
                    D.push_back(v);
                }
                else if (op == 3)
                    D.pop_front();
                else if (op == 4)
                    D.pop_back();
            }
            D.print();
            break;
        }
        case 20:
        {
            cout << "Enter number of nodes for level-order build and values:\n";
            int n;
            cin >> n;
            vector<int> v(n);
            for (int i = 0; i < n; i++)
                cin >> v[i];
            BinaryTree T;
            T.build_from_vector(v);
            cout << "Preorder: ";
            T.preorder(T.root);
            cout << "\n";
            cout << "Inorder: ";
            T.inorder(T.root);
            cout << "\n";
            cout << "Postorder: ";
            T.postorder(T.root);
            cout << "\n";
            break;
        }
        case 21:
        {
            BST tree;
            cout << "Enter count and values to insert into BST:\n";
            int k;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                tree.insert(x);
            }
            cout << "Inorder (should be sorted): ";
            tree.inorder();
            break;
        }
        default:
            cout << "Invalid choice\n";
            break;
        }
    }
    cout << "Goodbye\n";
    return 0;
}
