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
    // int ans = 0;
    // vector<int> Ancestor;
    // void Helper(TreeNode* root, int A){
    //     if(root == NULL){
    //         return;
    //     }
    //     Ancestor.push_back(A);
    //     Helper(root->left, root->val);
    //     Helper(root->right, root->val);

    //     for(int i=0;i<Ancestor.size();i++){
    //         int diff = abs(Ancestor[i] - root->val);
    //         // cout<<Ancestor[i]<<" "<<root->val<<" "<<diff<<endl;
    //         ans = max(ans, diff);
    //     }
    //     Ancestor.pop_back();
    // }

    // int maxAncestorDiff(TreeNode* root) {
    //     Helper(root->left, root->val);
    //     Helper(root->right, root->val);

    //     return ans;
    // }

    int diff = 0;

    void Helper(TreeNode* root, int minVal, int maxVal){
        if(!root)
            return;
        
        diff = max(diff, max(abs(minVal - root->val), abs(maxVal - root->val)));

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        Helper(root->left, minVal, maxVal);
        Helper(root->right, minVal, maxVal);
    }


    int maxAncestorDiff(TreeNode* root){
        int minVal = root->val;
        int maxVal = root->val;

        Helper(root, minVal, maxVal);
        return diff;
    }
};
