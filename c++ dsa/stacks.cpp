#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
}

#define size 5
class Stack{

    int arr[size];
    int top;

public:
    Stack(){
        top = -1;
    }


void push(int val){
        if(top == size-1){
            cout<< "Stack Overflow" <<endl;
            return;
        }
        arr[++top] = val;
        cout<< val << " pushed to stack" <<endl;
    };
};
