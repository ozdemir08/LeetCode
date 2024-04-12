/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {

private:
	TreeLinkNode *rightestAtLeft, *leftestAtRight;
	
public:
    void connect(TreeLinkNode *root) {
  		if(!root || !root -> left)
  			return;

  		connect(root -> left);
  		connect(root -> right);

  		rightestAtLeft = root -> left;
  		leftestAtRight = root -> right;
  		while(rightestAtLeft){
  			rightestAtLeft -> next = leftestAtRight;
  			rightestAtLeft = rightestAtLeft -> right;
  			leftestAtRight = leftestAtRight -> left;
  		}
    }
};