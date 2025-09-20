#include <iostream>
using namespace std;

int getSum(int *arr,int n){
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    //creation of array in heap from stack
    //variable size array

    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=getSum(arr,n);
    cout<<"Sum is "<<ans<<endl;

    while(true){
        int i=5;
    }

    while(true){
        int* ptr = new int;
        //8bytes in stack and 4bytes in heap
    }
}

//static location-memory automatically released
//dynamic location-memory manually released
//by using delete keyword

//new keyword is used to create dynamic memory

//delete keyword is used to delete dynamic memory
