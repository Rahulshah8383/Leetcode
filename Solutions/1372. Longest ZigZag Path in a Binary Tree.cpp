/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int Helper(TreeNode* root, bool flag){
        if(root == NULL){
            return -1;
        }

        int left = 1 + Helper(root->left, false);
        int right = 1 + Helper(root->right, true);

        ans = max(ans, max(left, right));

        return flag ? left : right;
    }

    int longestZigZag(TreeNode* root) {
        Helper(root, true);
        return ans;
    }
};
