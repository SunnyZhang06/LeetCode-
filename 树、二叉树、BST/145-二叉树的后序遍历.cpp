

3//145二叉树的后序遍历

//递归
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> res;
	helper(root,res);
	return res;
}
void helper(TreeNode* root,vector<int>& res)
{
	if(root==NULL)
		return;
	if(root->left!=NULL)
		helper(root->left,res);	
	if(root->right!=NULL)
		helper(root->right,res);
	res.push_back(root->val);
}

//迭代（借助两个栈）
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	TreeNode* p=root;
	
	if(p!=NULL)
		s1.push(p);
	
	while(!s1.empty())
	{
		p=s1.top();
		s1.pop();
		s2.push(p);
		if(p->left!=NULL)
			s1.push(p->left);
		if(p->right!=NULL)
			s1.push(p->right);
	}
	while(!s2.empty())
	{
		p=s2.top();
		s2.pop();
		res.push_back(p->val);
	}
	return res;
}