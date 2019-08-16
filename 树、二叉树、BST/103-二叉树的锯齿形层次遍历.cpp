

6//103二叉树的锯齿形层次遍历

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if(root==NULL)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	int cnt=0;
	
	while(!q.empty())
	{
		cnt++;
		vector<int> oneLevel;
		for(int i=q.size();i>0;i--)
		{
			TreeNode* t=q.front();q.pop();
			oneLevel.push_back(t->val);
			if(t->left)
				q.push(q->left);
			if(t->right)
				q.push(q->right);
		}
		if(cnt%2==0)//偶数层翻转
			reverse(oneLevel.begin(),oneLevel.end());
		res.push_back(oneLevel);
	}
	return res;
}
