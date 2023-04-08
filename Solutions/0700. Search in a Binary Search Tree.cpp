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
    TreeNode* searchBST(TreeNode* root, int val) {
        // iterative approach
    /*
        while(root != NULL && root->val != val){
            root = (root->val < val)?root->right:root->left;
        }
        return root;
    */

    // Recurcive approach
        if(root == NULL){
            return root; 
        }

        if(root->val == val){
            return root;
        }

    // we can combine if(root == NULL) and if(root->val == val) with or(||) operator

        if(root->val < val){
            return searchBST(root->right, val);
        }
        return searchBST(root->left, val);
    }
};
