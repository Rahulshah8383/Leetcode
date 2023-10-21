class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
        return {1};
    }

    std::vector<std::vector<int>> ans(rowIndex + 1); // Initialize ans with rowIndex + 1 rows

    ans[0] = {1};

    for (int i = 1; i <= rowIndex; i++) {
        ans[i].push_back(1); // First element of the row is always 1
        for (int j = 1; j < i; j++) {
            int sum = ans[i - 1][j - 1] + ans[i - 1][j];
            ans[i].push_back(sum);
        }
        ans[i].push_back(1); // Last element of the row is always 1
    }

    return ans[rowIndex];

    }
};
