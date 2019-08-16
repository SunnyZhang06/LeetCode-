
13//101对称二叉树

bool isSymmetric(TreeNode* root)
{
	if(root==NULL)
		return true;
	return isSym(root->left,root->right);
}

bool isSym(TreeNode* p,TreeNode* q)
{
	if(p==NULL && q==NULL)
		return true;
	if(p==NULL || q==NULL)
		return false;
	if(p->val==q->val)
		return isSym(p->left,q->right)&&isSym(p->right,q->left);
	return false;
}

