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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return -1;
        }
            
        vector<int> ans;
        inorder(root, ans);

        return ans[k-1];
    }
    */
    int Solver(TreeNode* root,int i, int k){
        if(root == NULL){
            return -1;
        }

        // Left
        int left = Solver(root->left, i, k);
        if(left == NULL){
            return left;
        }

        // Node
        i++;
        if(i == k){
            return root->val;
        }

        // R
        return Solver(root->right, i, k);
    }

    int kthSmallest(TreeNode* root, int k){
        return Solver(root, 0, k);
    }

};
