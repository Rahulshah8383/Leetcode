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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int maxSum = root->val;
        int maxlevel = 1;
        int level = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int currentSum = 0;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                currentSum += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            if(currentSum > maxSum){
                maxSum = currentSum;
                maxlevel = level;
            }
            level++;
        }
        return maxlevel;
    }
};
