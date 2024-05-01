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
    int Helper(TreeNode* root, int ans){
        if(!root){
            return 0;
        }
            
        ans = ans*10 + root->val;

        if(!root->left && !root->right)
            return ans;

        return Helper(root->left, ans) + Helper(root->right, ans);   
    }

    int sumNumbers(TreeNode* root) {
        return Helper(root, 0);
    }
};
