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
    int mini(TreeNode* root){
        if(root == NULL){
            return -1;
        }
        
        while(root->left != NULL){
            root = root->left;
        }
        
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return nullptr;
        }
        
        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            
            if(root->left != nullptr && root->right == nullptr){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            
            if(root->left == nullptr && root->right != nullptr){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            
            if(root->left != nullptr && root->right != nullptr){
                int min = mini(root->right);
                root->val = min;
                root->right = deleteNode(root->right, min);
            }
        }
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        
        return root;
    }
};
