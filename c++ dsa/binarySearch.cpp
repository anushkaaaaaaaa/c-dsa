#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key) {
    //base case

    //element not found

    if (s>e){
        return false;
    
    int mid  = s + (e-s)/2;

    //element found
    if(arr[mid] == key){
        return true;
    }
    //right part
    if(arr[mid] < key) {
        return binarySearch( arr, mid+1 , e, key);
    }
    //left part
    else{
        return binarySearch( arr, s, mid-1, key);
    }
    }

}

int main(){
    int arr[6] = {2,4,6,8,10,12};
    int key = 8;
    bool ans = binarySearch(arr,2,8,key);
    if(ans){
        cout<<"Key is present"<<endl;
    }
    else{
        cout<<"Key is not present"<<endl;
    }
}
