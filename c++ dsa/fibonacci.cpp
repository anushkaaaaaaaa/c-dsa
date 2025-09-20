#include <iostream>
using namespace std;

int fib(int i){
    //base case
        if(i==0){
            return 0;
        }
        if(i==1){
            return 1;
        }

        int ans = fib(i-1)+fib(i-2);
        
        return ans;
}

int main(){
    int n;
    cin>>n;
    int ans = fib(n);
    cout<<ans<<endl;
}