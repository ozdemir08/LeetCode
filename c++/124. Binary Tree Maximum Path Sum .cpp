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
    int maxPathSum(TreeNode* root) {
        maxChildSum(root);
        return currentMaxPathSum;
    }
    
private:
    int currentMaxPathSum = INT_MIN;
    
    int maxChildSum(TreeNode* root){
        if(!root)
            return 0;
        
        int left = max(0, maxChildSum(root -> left));
        int right = max(0, maxChildSum(root -> right));
        
        currentMaxPathSum = max(currentMaxPathSum, root -> val + left + right);
        return root -> val + max(left, right);
    }
};