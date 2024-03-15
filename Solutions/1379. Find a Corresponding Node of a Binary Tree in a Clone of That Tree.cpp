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
    TreeNode* ans = nullptr;
    void Helper(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(cloned == nullptr){
            return;
        }
        
        if(original == target){
            ans = cloned;
            return;
        }

        Helper(original->left, cloned->left, target);
        Helper(original->right, cloned->right, target);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        Helper(original, cloned, target);
        return ans;
    }
};
