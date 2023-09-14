class Solution {
public:                                                                             
    int candy(vector<int>& rating) {
        int n = rating.size();

        vector<int> left(n, 1);
        for (int i = 1; i < n; i++) {
            if (rating[i] > rating[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        vector<int> right(n, 1);
        for (int j = n - 2; j >= 0; j--) {
            if (rating[j] > rating[j + 1]) {
                right[j] = right[j + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};
