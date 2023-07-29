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
    */

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode *front = q.front();
                q.pop();

                temp.push_back(front->val);
                if(front->left != nullptr){
                    q.push(front->left);
                }

                if(front->right != nullptr){
                    q.push(front->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
