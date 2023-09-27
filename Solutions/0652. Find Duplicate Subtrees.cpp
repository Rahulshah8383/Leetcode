class Solution {
public:
    string Helper(TreeNode* root, unordered_map<string, int> &subtrees, vector<TreeNode*> &duplicate){
        if(root == nullptr){
            return "$";
        }

        string left = Helper(root->left, subtrees, duplicate);
        string right = Helper(root->right, subtrees, duplicate);

        string s = left + "," + right + "," + to_string(root->val);

        if(subtrees[s] == 1){
            duplicate.push_back(root);
        }

        subtrees[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtrees;
        vector<TreeNode*> duplicate;

        Helper(root, subtrees, duplicate);
        return duplicate;
    }
};
