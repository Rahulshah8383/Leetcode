#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;

        // Calculate the nearest smaller element on the left
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[i] < arr[s1.top()]) {
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        // Calculate the nearest smaller element on the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[i] <= arr[s2.top()]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + static_cast<long long>((i - left[i]) * (right[i] - i) % MOD) * arr[i]) % MOD;
        }

        return static_cast<int>(result);
    }
};
