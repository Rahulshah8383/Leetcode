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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return vector<vector<int>> ();
        }
        
        vector<vector<int>> ans;
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        bool LefttoRight = true;

        while(!pendingNode.empty()){
            int levelsize = pendingNode.size();
            vector<int> levelNodes(levelsize);

            for(int i=0;i<levelsize;i++){
                TreeNode* front = pendingNode.front();
                pendingNode.pop();

                int index = LefttoRight ? i : levelsize-i-1;
                levelNodes[index] = front->val;

                if(front->left != NULL){
                    pendingNode.push(front->left);
                }
                if(front->right != NULL){
                    pendingNode.push(front->right);
                }
            }
            LefttoRight = !LefttoRight;
            ans.push_back(levelNodes);
        }
        return ans;
    }
};
