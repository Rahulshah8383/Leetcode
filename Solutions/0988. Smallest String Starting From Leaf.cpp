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
    void Helper(TreeNode* root, vector<string> &str, string temp){
        if(root->left == NULL && root->right == NULL){
            char c = 97 + root->val;
            temp.push_back(c);
            reverse(temp.begin(), temp.end());
            str.push_back(temp);
        }

        char c = 97 + root->val;
        temp.push_back(c);
        if(root->left)
            Helper(root->left, str, temp);
        if(root->right)
            Helper(root->right, str, temp);
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> str;

        Helper(root, str, "");
        sort(str.begin(), str.end());
        // for(auto it : str){
        //     cout<<it<<" ";
        // }

        return str[0];
    }
};
