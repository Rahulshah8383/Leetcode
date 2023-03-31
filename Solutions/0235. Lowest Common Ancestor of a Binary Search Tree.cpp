/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL; // Tree is empty, return NULL
        }
    
        if (root == p || root == q) {
            return root; // One of the nodes is the root, return the root
        }
    
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
    
        if (leftLCA != NULL && rightLCA != NULL) {
            return root; // p and q are in different subtrees, so root is the LCA
        } 
        else if (leftLCA != NULL) {
            return leftLCA; // Both p and q are in the left subtree
        } 
        else {
            return rightLCA; // Both p and q are in the right subtree
        }
    }
};
