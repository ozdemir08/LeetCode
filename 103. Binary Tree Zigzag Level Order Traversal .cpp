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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> res; 
    	if(!root)
    		return res;

		int depth = 0, currentLevel = 0, nextLevel = 1;
    	vector< TreeNode* > level[2];
    	level[0].push_back(root);
        
    	while(!level[currentLevel].empty()){
    		res.push_back(vector<int>());

    		for(int i=level[currentLevel].size() - 1;i>=0;i--){
    			TreeNode* node = level[currentLevel][i];
    			res[depth].push_back(node -> val);
    			if(depth % 2 == 0){
    				if(node -> left)
    					level[nextLevel].push_back(node -> left);
    				if(node -> right)
    					level[nextLevel].push_back(node -> right);
    			}
    			else{
    				if(node -> right)
    					level[nextLevel].push_back(node -> right);
    				if(node -> left)
    					level[nextLevel].push_back(node -> left);
    			}
    		}
            level[currentLevel].clear();
    		currentLevel = 1 - currentLevel;
    		nextLevel = 1 - nextLevel;
    		depth++;
    	}
    	return res;
    }
};

class Solution2{
	public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		if(!root)
			return vector<vector<int>>();

		vector<vector<int>> result;
		queue< TreeNode* > nodesQueue;
		bool leftToRight = true;
		nodesQueue.push(root);

		while(!nodesQueue.empty()){
			int size = nodesQueue.size();
			vector<int> currentLevel(size);
			for(int i=0;i<size;i++){
				TreeNode *node = nodesQueue.front();
				nodesQueue.pop();

				int index = leftToRight ? i : size - i - 1;
				currentLevel[index] = node -> val;
				if(node -> left)
					nodesQueue.push(node -> left);
				if(node -> right)
					nodesQueue.push(node -> right);
			}
			leftToRight = !leftToRight;
			result.push_back(currentLevel);
		}
		return result;
    }
}