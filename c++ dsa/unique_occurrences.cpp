#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 7. Unique occurrences of elements in an array
void unique_occurrences(){
    int n;
    cout<< "enter number of elements: ";
    cin>>n;
    vector<int> a(n);
    cout<< "enter elements: ";
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int count = 1;
    for(int i = 1 ; i < n ; i++){
        if(a[i] == a[i-1]){
            count++;
        }
        else{
            cout<<a[i-1]<<" occurs "<<count<<" times\n";
            count = 1;
        }
    }
    cout<<a[n-1]<<" occurs "<<count<<" times\n";
    }