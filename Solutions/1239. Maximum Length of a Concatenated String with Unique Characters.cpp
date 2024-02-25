class Solution {
public:
    void solve(const vector<string>& arr, vector<int>& vis, int i, int& ans, int currLength) {
        if (i == arr.size()) {
            ans = max(ans, currLength);
            return;
        }

        // Include the current string if no common characters
        bool check = true;
        unordered_set<char> st;

        for (char c : arr[i]) {
            if (vis[c - 'a'] || st.count(c) > 0) {
                check = false;
                break;
            }
            st.insert(c);
        }

        // Take
        if (check) {
            for (char c : arr[i]) {
                vis[c - 'a'] = 1;
            }
            solve(arr, vis, i + 1, ans, currLength + arr[i].size());
            for (char c : arr[i]) {
                vis[c - 'a'] = 0;
            }
        }

        // Not Take The string
        solve(arr, vis, i + 1, ans, currLength);
    }

    int maxLength(vector<string>& arr) {
        vector<int> vis(26, 0);
        int ans = 0;
        solve(arr, vis, 0, ans, 0);
        return ans;
    }
};
