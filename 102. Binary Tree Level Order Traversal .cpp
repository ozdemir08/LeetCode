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
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> res;
    	int cur = 0, next = 1; 
        queue< TreeNode* > q[2];
        q[cur].push(root);
        while(!q[cur].empty()){
        	
        	vector<int> level;
        	while(!q[cur].empty()){
	            TreeNode* node = q[cur].front();
	            q[cur].pop();

	            level.push_back(node -> val);

	            if(node -> left)
	            	q[next].push(node -> left);

	            if(node -> right)
	            	q[next].push(node -> right);
            }
            res.push_back(level);
            cur = 1 - cur;
            next = 1 - next;
        }
        return res;
    }
};

class Solution2 {
private:
	vector< vector<int> > res;

public:

	void dfs(TreeNode* node, int depth){
		if(!node)
			return;

		if(res.size() == depth)
			res.push_back(vector<int>());

		res[depth].push_back(node -> val);
		dfs(node -> left, depth + 1);
		dfs(node -> right, depth + 1);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		dfs(root, 0);
		return res;
	}
}