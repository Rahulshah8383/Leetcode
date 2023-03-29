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
    vector<vector<int>> Traversal;

    void Helper(TreeNode* root, int depth){
        if(root == NULL){
            return;
        }

        if(Traversal.size() == depth){
            Traversal.push_back(vector<int>());
        }

        Traversal[depth].push_back(root->val);
        Helper(root->left, depth+1);
        Helper(root->right, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        Helper(root, 0);
        return Traversal;

    }
};
