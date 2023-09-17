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
    /*
    int Height(TreeNode *node){
        if (node == NULL){
            return 0;
        }
    
        int a = 1 + Height(node->left);
        int b = 1 + Height(node->right);
    
        return max(a, b);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        bool left =  isBalanced(root->left);
        bool right =  isBalanced(root->right);

        int diff = abs(Height(root->left) - Height(root->right)) <= 1;

        if(left && right && diff){
            return true;
        }
        return false;
    }
    */

    pair<bool, int> Helper(TreeNode* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = Helper(root->left);
        pair<bool, int> right = Helper(root->right);

        int leftAns = left.first; 
        int rightAns = right.first;
        // diff = left height - right height
        int diff = abs(left.second - right.second) <= 1;
        // height
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.second = false;
        }
        return ans;
    }

    bool isBalanced(TreeNode* root){
        return Helper(root).first;
    }
};
