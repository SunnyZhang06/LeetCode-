

8//111二叉树的最小深度

int minDepth(TreeNode* root)
{
	
	/*
	if (root==NULL) 
		return 0;
	if (root->left==NULL) 
		return 1 + minDepth(root->right);
	if (root->right==NULL) 
		return 1 + minDepth(root->left);
	return 1 + min(minDepth(root->left), minDepth(root->right));
	*/
	if(root==NULL)
		return 0;
	int left=minDepth(root->left);
	int right=minDepth(root->right);
	if(root->left && root->right)//左右子节点都不为空，则选左右子树高度最小的
		return 1+min(left,right);
	return 1+left+right;
}
