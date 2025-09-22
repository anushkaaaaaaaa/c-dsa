#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(11);

    q.push(27);
    
    q.push(33);

    cout<<q.size()<<" :Size of queue"<<endl;
    cout<<q.front()<<" :Front element"<<endl;
    cout<<q.back()<<" :Last element"<<endl;
    q.pop();
    cout<<q.size()<<" :New Size"<<endl;
    cout<<q.front()<<" :Front"<<endl;
    cout<<q.back()<<" :Back"<<endl;
}

//Implement a queue using array
#define size 5
class Queue{
    int arr[size];
    int front , rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }

    //addition from rear
void enqueue(int val){
    if(rear == size-1){
        cout<<"Queue is full"<<endl;
    }
    cout<<arr[rear]<<endl;
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        arr[rear] = val;
    }
    else{
        rear++;
    }
}

    //deletion from front
void dequeue(){
    if(front == -1 && rear == -1){
        cout<<"Queue is empty"<<endl;
    }
    cout<<arr[front]<<endl;
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}
};  