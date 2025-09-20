#include <iostream>
using namespace std;
//Bubble sort by Recursion
void sortArray(int *arr, int n){

    //base case - already sorted

    if( n == 0 || n == 1){
        return ;
    }
    for(int i=0; i<n-1; i++){
        // 1 case solve karlia - largest element ko end me rakh dega
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    //Recursive call
    sortArray(arr, n-1);
}

int main(){
    int arr[5] = {2,4,1,6,8};
    sortArray(arr, 5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
   
}