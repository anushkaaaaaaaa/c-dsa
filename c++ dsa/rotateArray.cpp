#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reverseArray(int arr[],int start, int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

}

void rotateArray(int arr[], int n, int k, string direction){
    k = k%n;
    if(direction == "right"){
        reverseArray(arr,0,n-1);
        
        reverseArray(arr,0,k-1);

        reverseArray(arr,k,n-1);
    }
    else if(direction == "left"){
        reverseArray(arr,0,k-1);

        reverseArray(arr,k,n-1);

        reverseArray(arr,0,n-1);
    }
}
int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 2;
    string dir = "right";

    rotateArray(nums, n, k, dir);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}