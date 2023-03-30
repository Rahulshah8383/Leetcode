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
    bool Helper(TreeNode* root, long min,long max){
        if(root == NULL){
            return true;
        }

        if(root->val > min && root->val < max){
            bool leftTree = Helper(root->left, min, root->val);
            bool rightTree = Helper(root->right, root->val, max);

            return leftTree && rightTree;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return Helper(root, LONG_MIN, LONG_MAX);
    }
};
