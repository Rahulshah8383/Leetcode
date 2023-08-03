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
// this function will return all full binary trees for n nodes...
    vector<TreeNode*> get_trees(int n,vector<vector<TreeNode*>>&dp){
        if(n%2==0){
            // when n is even we will not have any full binary tree..
            return {};
        }
        if(n==1){
            TreeNode *root=new TreeNode(0);
            return {root};
        }
        // if we have all trees for a given number of nodes 'n'...
        if(dp[n].size()>0){
            return dp[n];
        }
        vector<TreeNode*>ans;
        // we will iterate on odd number of nodes and not on even number of nodes....
        for(int i=1;i<n;i+=2){
            // we are considering i nodes on left subtree and (n-1-i) nodes on right subtree...
            vector<TreeNode*>left_tree=get_trees(i,dp);
            vector<TreeNode*>right_tree=get_trees(n-1-i,dp);
            for(auto sub_left:left_tree){
                for(auto sub_right:right_tree){
                    TreeNode *node=new TreeNode(0);
                    node->left=sub_left; // sub_left is left child of node...
                    node->right=sub_right;// sub_right is right child of node....
                    ans.push_back(node);
                }
            }
        }
        return dp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>>dp(n+1); // it will be used for memoization....
        return get_trees(n,dp);
    }
};
