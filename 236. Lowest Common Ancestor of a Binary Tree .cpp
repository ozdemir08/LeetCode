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
private:
    TreeNode* commonAncestor;
    // 0 : no p and no q in this subtree
    // 1 : p or q in this subtree but not both
    // 2 : p and q in this subtree
    int find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return 0;
        int self = 0;
        
        if(root == p)
            self++;
        if(root == q)
            self++;
        
        int left = find(root -> left, p, q);
        int right = find(root -> right, p, q);
        int res = self + left + right;
        if(self == 2 || (left != 2 && right != 2 && res == 2))
            commonAncestor = root;
        return res;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        commonAncestor = root;
        find(root, p, q);
        return commonAncestor;
    }
};