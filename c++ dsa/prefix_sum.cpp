#include <iostream>
#include <vector>

using namespace std;

vector<int> calculatePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n);
    
    if (n == 0) return prefixSum;

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> prefixSum = calculatePrefixSum(arr);

    cout << "Prefix Sum array: ";
    for (int num : prefixSum) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
