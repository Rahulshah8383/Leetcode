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
    /*
    bool BFS(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        bool even_level = true;

        while(!q.empty()){
            int size = q.size();

            int prev = even_level ? INT_MIN : INT_MAX;

            while(size--){
                TreeNode* front = q.front();
                q.pop();

                if(even_level && (front->val%2 == 0 || front->val <= prev)){
                    return false;
                }

                if(!even_level && (front->val%2 != 0 || front->val >= prev)){
                    return false;
                }

                prev = front->val;

                if(front->left != nullptr){
                    q.push(front->left);
                }

                if(front->right != nullptr){
                    q.push(front->right);
                }
            }

            even_level = !even_level;
        }

        return true;
    }
    */

    vector<int> levelPrev;

    bool DFS(TreeNode* root, int level){
        if(!root){
            return true;
        }

        if(level%2 == root->val%2){
            return false;
        }

        if(level >= levelPrev.size()){
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0){
            if((level % 2 == 0 && root->val <= levelPrev[level])
            ||
            (level % 2 != 0 && root->val >= levelPrev[level])){
                return false;
            }
        }

        levelPrev[level] = root->val;
        return DFS(root->left, level+1) && DFS(root->right, level+1);
    }

    bool isEvenOddTree(TreeNode* root) {
        // return BFS(root);

        return DFS(root, 0);
    }
};
