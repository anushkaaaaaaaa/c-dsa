#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int s=0;
        int e=arr.size()-1;
        vector<int> res;
        int p =-1;
        int q=-1;
        int count = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==target){
                p=mid;
                e =mid-1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        s=0;
        e=n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==target){
                q=mid;
                s=mid+1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return {p,q};
        count = arr[q]-arr[p]+1;
        return count;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1,2,2,2,3,4,5};
    int target = 2;
    int freq = sol.countFreq(arr,target);
    cout<<"Frequency of "<<target<<" is: "<<freq<<endl;
    return 0;
}
