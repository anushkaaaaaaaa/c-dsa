#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public:
    int* arr;
    int top;
    int size;


    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek()<<endl; //30
    st.pop();   
    cout<<st.peek()<<endl; //20
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl; //1 (true)
    st.pop(); //Stack Underflow
    return 0;
}