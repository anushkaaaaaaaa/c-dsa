// Sliding-window solution to find maximum sum of any subarray of size k
// Usage: provide n k followed by n integers on stdin.
// Example input: 8 3 2 1 5 1 3 2 1 4  -> output: 9

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k <= 0 || k > n) {
        cout << "Invalid\n";
        return 0;
    }

    long long window_sum = 0;
    for (int i = 0; i < k; ++i) window_sum += a[i];
    long long max_sum = window_sum;

    for (int i = k; i < n; ++i) {
        window_sum += a[i];
        window_sum -= a[i - k];
        if (window_sum > max_sum) max_sum = window_sum;
    }

    cout << max_sum << '\n';
    return 0;
}
