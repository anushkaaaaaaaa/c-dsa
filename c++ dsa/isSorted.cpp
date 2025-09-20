#include <iostream>
using namespace std;

bool isSorted(int *arr, int size){
        if(size == 0 || size == 1){
            return true;
        }
        if(arr[0]>arr[1]){
            return false;
        }
        else{
            bool remainingPart = isSorted(arr+1,size-1);
            return remainingPart;
        }
}

int sum(int arr[],int size){
    //base case
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    int remainingPart = sum(arr+1,size-1);
    return arr[0] + remainingPart;
}


int main(){
    int arr[7] = {1,8,5,7,90,12,234};
    int size = 7;
    bool ans = isSorted(arr,size);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    int getSum = sum(arr,size);
    cout<< getSum << endl;

}