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
    int ans = 1;
    void Helper(TreeNode* root, int maxi){
        if(root == NULL){
            return;
        }

        if(root->val >= maxi){
            ans++;
            // cout<<root->val<<" ";
            maxi = max(maxi, root->val);
        }

        Helper(root->left, maxi);
        Helper(root->right, maxi);
    }

    int goodNodes(TreeNode* root) {
        int max = root->val;

        if(root->left == NULL && root->right == NULL){
            return ans;
        }

        Helper(root->left, max);
        Helper(root->right, max);
        return ans;
    }
};
