class Solution {
public:
    bool isValidBST(TreeNode *root, long long mn, long long mx){
        if(!root) return true;
        if(root -> val >= mx || root -> val <= mn) return false;
        return isValidBST(root -> left, mn, root -> val) && isValidBST(root -> right, root -> val, mx);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
};