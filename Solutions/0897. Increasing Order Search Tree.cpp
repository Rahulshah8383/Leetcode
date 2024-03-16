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
    /*
private:
    void inorderTraversal(TreeNode* root, vector<int>& values) {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        // Perform in-order traversal to get the values in increasing order
        vector<int> values;
        inorderTraversal(root, values);

        TreeNode* newRoot = new TreeNode(values[0]);
        TreeNode* currRoot = newRoot;

        for(int i=1;i<values.size();i++){
            currRoot->right =new TreeNode(values[i]);
            currRoot =  currRoot->right;
        }

        return newRoot;
    }
    */

public:
    void inorder(TreeNode*& root, TreeNode* temp){
        if(!root) return;

        inorder(root->left, temp);
        temp->right = new TreeNode(root->val);
        temp = temp->right;
        inorder(root->right, temp);
    }

    TreeNode* increasingBST(TreeNode* root){
        TreeNode *ans = new TreeNode();
        TreeNode *temp = ans;

        inorder(root, temp);
        return ans;
    }
};
