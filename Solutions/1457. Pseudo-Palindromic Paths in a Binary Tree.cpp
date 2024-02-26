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
    int Helper(TreeNode* root, vector<int> freq){
        if(!root)
            return 0;

        freq[root->val]++;
        if(!root->left && !root->right){
            int odd = 0;
            for(int i=0;i<10;i++){
                if(freq[i]%2)
                    odd++;
            }
            freq[root->val]--;
            return odd < 2;
        }

        int a = Helper(root->left, freq);
        int b = Helper(root->right, freq);
        freq[root->val]--;
        return a+b;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        return Helper(root, freq);
    }
};
