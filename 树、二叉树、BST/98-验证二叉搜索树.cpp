
11//98验证二叉搜索树

bool isValidBST(TreeNode* root)
{
	//思路：中序遍历，然后判断数组是否升序
	if(root==NULL)
		return true;
	vector<int> res;
	inOrder(root,res);
	for(int i=0;i<res.size()-1;++i)
	{
		if(res[i]>=res[i+1])
			return false;
	}
	return true;
	
	//思路2：利用本身性质，左结点<根结点<右结点
	return isValid(root,LONG_MIN,LONG_MAX);
}

bool isValid(TreeNode* root,long min,long max)
{
	if(root==NULL)
		return true;
	if(root->val <=min || root->val>=max)
		return false;
	return isValid(root->left,min,root->val)&&isValid(root->right,root->val,max);	
}
