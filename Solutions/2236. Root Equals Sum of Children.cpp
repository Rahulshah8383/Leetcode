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
    pair<bool, int> Helper(TreeNode* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(true, root->val);
            return p;
        }

        pair<bool, int> left = Helper(root->left);
        pair<bool, int> right = Helper(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        int cond = root->val == (left.second + right.second);

        pair<bool, int> ans;
        if(leftAns && rightAns && cond){
            ans.first = true;
            ans.second = 2*root->val;
        }
        else{
            ans.first = false;
        }
        return ans;
    }

    bool checkTree(TreeNode* root) {
        return Helper(root).first;
    }
};
