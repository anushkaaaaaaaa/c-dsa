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