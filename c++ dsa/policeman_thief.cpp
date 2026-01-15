#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int catchThieves(vector<char>& arr, int k) {
    int n = arr.size();
    
    // Store indices of policemen and thieves
    vector<int> police, thieves;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P') {
            police.push_back(i);
        } else {
            thieves.push_back(i);
        }
    }
    
    int caught = 0;
    int p = 0;  
    int t = 0;  
    
   
    while (p < police.size() && t < thieves.size()) {

        if (abs(police[p] - thieves[t]) <= k) {
            caught++;
            p++;
            t++;
        }
        
        else if (thieves[t] < police[p]) {
            t++;
        }
        
        else {
            p++;
        }
    }
    
    return caught;
}

int main() {
    
    vector<char> arr1 = {'P', 'T', 'T', 'P', 'T'};
    int k1 = 1;
    cout << "Test Case 1:" << endl;
    cout << "Array: [P, T, T, P, T], k = " << k1 << endl;
    cout << "Maximum thieves caught: " << catchThieves(arr1, k1) << endl;
    cout << "Expected: 2" << endl << endl;
    
    
    vector<char> arr2 = {'T', 'T', 'P', 'P', 'T', 'P'};
    int k2 = 2;
    cout << "Test Case 2:" << endl;
    cout << "Array: [T, T, P, P, T, P], k = " << k2 << endl;
    cout << "Maximum thieves caught: " << catchThieves(arr2, k2) << endl;
    cout << "Expected: 3" << endl << endl;
    
    
    vector<char> arr3 = {'P', 'P', 'P'};
    int k3 = 1;
    cout << "Test Case 3 (No thieves):" << endl;
    cout << "Array: [P, P, P], k = " << k3 << endl;
    cout << "Maximum thieves caught: " << catchThieves(arr3, k3) << endl;
    cout << "Expected: 0" << endl << endl;
    
    
    vector<char> arr4 = {'T', 'T', 'T'};
    int k4 = 1;
    cout << "Test Case 4 (No police):" << endl;
    cout << "Array: [T, T, T], k = " << k4 << endl;
    cout << "Maximum thieves caught: " << catchThieves(arr4, k4) << endl;
    cout << "Expected: 0" << endl << endl;
    

    vector<char> arr5 = {'T', 'P', 'T', 'P', 'T'};
    int k5 = 100;
    cout << "Test Case 5 (Large k):" << endl;
    cout << "Array: [T, P, T, P, T], k = " << k5 << endl;
    cout << "Maximum thieves caught: " << catchThieves(arr5, k5) << endl;
    cout << "Expected: 2" << endl;
    
    return 0;
}
