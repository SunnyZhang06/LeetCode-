

5//107二叉树的层次遍历II(自底向上遍历)

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> res;
	if(root==NULL)
		return res;
	
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		vector<int> oneLevel;
		for(int i=q.size();i>0;i--)//q.size()代表每层元素个数
		{
			TreeNode* t=q.front();q.pop();
			oneLevel.push_back(t->val);//存储每一层的元素
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
		//res.push_back(oneLevel);
		res.insert(res.begin(),oneLevel);
	}
	return res;
}
