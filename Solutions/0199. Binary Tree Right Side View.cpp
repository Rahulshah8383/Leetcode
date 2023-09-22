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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        vector<vector<int>> level_order;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
            }
            level_order.push_back(temp);
        }
        
        for(int i=0;i<level_order.size();i++){
            for(int j=0;j<level_order[i].size();j++){
                if(j==level_order[i].size()-1){
                    ans.push_back(level_order[i][j]);
                }
            }
        }
        return ans;

        /*
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        map<int, int> rightNode;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<TreeNode*, int> front = q.front();
            q.pop();
            
            TreeNode* frontNode = front.first;
            int hd = front.second;
            
            rightNode[hd] = frontNode->val;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd+1));
        
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto it : rightNode){
            ans.push_back(it.second);
        }
        
        return ans;
        */
    }
};
