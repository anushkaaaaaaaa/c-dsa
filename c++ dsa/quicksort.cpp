#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=arr[s];
   
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
           
        }
    }
    //place pivot at right position
    int pivotIndex= s+cnt;
    swap(arr[pivotIndex],arr[s]);
    
    //left and right part
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex; 
}

//Quick Sort
//we have an array, {3,5,1,8,2,4}
//yaha pe thodi si cheezein ulti hoti hai
//algo
//ek element uthalo and usko uski sahi jagah
//pe daaldo, in a way left me less than <e and right me >e
//this is called partition

void quickSort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return;
    }
    //recursive case
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

//{1,2,3,8,5,4}
//3 ke left me smaller than 3 and right me greater than 3

int main(){
    int arr[5]={3,5,1,8,2};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//Subsets and Subsequence of String
//arr[3]={1,2,3};
//{{},{1,2},{1,3},{2,3},{1},{2},{3},{1,2,3}}
//Power Set- Set of all subsets
//power set=2^n elements

//i/p- integer array
//o/p- subset array
