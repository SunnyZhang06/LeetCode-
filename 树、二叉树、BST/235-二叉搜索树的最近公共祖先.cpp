

19//235二叉搜索树的最近公共祖先

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{	
	//根据二叉搜索树的性质，左<根<右
	/*
	if(root==NULL)
		return root;
	if(root->val > max(p->val,q->val))
		return lowestCommonAncestor(root->left,p,q);
	else if(root->val < min(p->val,q->val))
		return lowestCommonAncestor(root->right,p,q);
	else
		return root;
		*/
		
	//非递归写法
	while(true)
	{
		if(root->val > max(p->val,q->val))
			root=root->left;
		else if(root->val < min(p->val,q->val))
			root=root->right;
		else
			break;
	}
	return root;      
	
}
