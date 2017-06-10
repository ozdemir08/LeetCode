/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> left, right;
        if(!root)
            return left;
            
        if(root -> left)
            left = inorderTraversal(root -> left);
        
        if(root -> right)
            right = inorderTraversal(root -> right);
        
        left.push_back(root -> val);
        for(int i=0;i<right.size();i++)
            left.push_back(right[i]);
        return left;
    }
};