#include <iostream>
using namespace std;

void sayDigits(int n,string arr[]){
    if(n==0){
        return;
    }
    int digit = n%10;
    n=n/10;
    

    sayDigits(n,arr);

    cout<< arr[digit] <<endl;
}

string arr[10] = {
                     "zero","one","two","three","four","five","six","seven","eight","nine"
                    };

int main(){
   
        int n;
        cin>>n;
        cout<< endl << endl << endl;
        sayDigits(n,arr);
        return 0;
    }


