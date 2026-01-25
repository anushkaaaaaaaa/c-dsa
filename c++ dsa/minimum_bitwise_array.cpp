#include <iostream>
#include <vector>
using namespace std;

// Key insight: x OR (x+1) sets the rightmost 0 bit of x to 1
// So if nums[i] has all 1s from bit 0 to bit k, then ans[i] must have bit k as 0
// We find the rightmost 0 bit in nums[i] and clear the bit just to its left

vector<int> minBitwiseArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        
        // If num is even (has a 0 in bit 0), no valid ans exists
        // because x OR (x+1) always has bit 0 set to 1
        if (num % 2 == 0) {
            ans[i] = -1;
            continue;
        }
        
        // Find rightmost 0 bit position
        int pos = 0;
        while ((num >> pos) & 1) {
            pos++;
        }
        
        // If pos is 0, num is already 1 with rightmost 0 at position 1
        // Actually pos starts from LSB, so pos=0 means bit 0 is 0
        // Since num is odd, pos will be >= 1
        
        // Clear the bit at position (pos - 1)
        ans[i] = num ^ (1 << (pos - 1));
    }
    
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> result = minBitwiseArray(nums);
    
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
