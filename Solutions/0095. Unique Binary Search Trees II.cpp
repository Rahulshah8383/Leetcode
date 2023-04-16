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
    vector<TreeNode*> Helper(int start, int end){
        vector<TreeNode*> List;
        if(start > end){
            List.push_back(NULL);
            return List;
        }

        if(start == end){
            TreeNode* node =new TreeNode(start);
            List.push_back(node);
        }

        if(end > start){
            for(int i=start; i<=end;i++){
                vector<TreeNode*> leftsubTree = Helper(start, i-1); // constructing left subtree
                vector<TreeNode*> rightsubTree = Helper(i+1, end);  // constructing right subtree 

                for(int j=0;j<leftsubTree.size();j++){
                    for(int k=0;k<rightsubTree.size();k++){
                        TreeNode* node =new TreeNode(i); // Create node with value i
                        node->left = leftsubTree[j];    // Connect left subtree rooted at leftSubTree[j]        
                        node->right = rightsubTree[k];   // Connect right subtree rooted at rightSubTree[k]

                        List.push_back(node);  // Add this tree(rooted at i) to ans data-structure
                    }
                }
            }
        }
        return List;
    }

    vector<TreeNode*> generateTrees(int n) {
        return Helper(1, n);
    }
};
