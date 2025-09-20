#include <iostream>
using namespace std;

int steps(int n, int a, int b, int c){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return steps(n-a,a,b,c)+steps(n-b,a,b,c)+steps(n-c,a,b,c);
}

int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cout<<steps(n,a,b,c)<<endl;
}



