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
private:
    void levelOrderTraversal(TreeNode* root, vector<int> &level){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            level.push_back(front->val);

            if(front->right){
                q.push(front->right);
            }

            if(front->left){
                q.push(front->left);
            }
        }
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> level;
        levelOrderTraversal(root, level);

        return level.back();
    }
};
