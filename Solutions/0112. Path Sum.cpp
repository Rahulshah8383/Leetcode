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
    // bool ans = false;
    // void Helper(TreeNode* root, int targetSum, int sum){
    //     if(root == NULL){
    //         return;
    //     }

    //     if(root->left == NULL && root->right == NULL){
    //         sum += root->val;
    //         if(sum == targetSum){
    //             ans = true;
    //             return;
    //         }
    //     }
    //     else{
    //         sum += root->val;
    //         cout<<root->val<<": "<<sum<<" ";
    //         Helper(root->left, targetSum, sum);
    //         cout<<endl;
    //         // sum -= root->val;
    //         Helper(root->right, targetSum, sum);
    //         sum += root->val;
    //         cout<<root->val<<": "<<sum<<" ";
    //     }

        
    //     // sum -= root->val;
    //     // Helper(root->left, targetSum, sum);
    // }

    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root == NULL){
    //         return NULL;
    //     }

    //     Helper(root, targetSum, 0);

    //     return ans;
    // }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }

        if(!root->left && !root->right){
            return targetSum == root->val;
        }

        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);

        return left_sum || right_sum;
    }
};
