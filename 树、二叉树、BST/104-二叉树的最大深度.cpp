

7//104二叉树的最大深度

int maxDepth(TreeNode* root)
{
	if(root==NULL)
		return 0;	
	int left=maxDepth(root->left);
	int right=maxDepth(root->right);
	return max(left,right)+1;
}











