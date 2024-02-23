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
    vector<vector<int>> ans;

    void Helper(TreeNode* root, int targetSum, vector<int> &temp){
        if(!root){
            return;
        }

        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum == root->val){
                ans.push_back(temp);
            }
        }

        Helper(root->left, targetSum - root->val, temp);
        Helper(root->right, targetSum - root->val, temp);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return ans;
        }

        vector<int> temp;
        Helper(root, targetSum, temp);
        return ans;
    }
};
