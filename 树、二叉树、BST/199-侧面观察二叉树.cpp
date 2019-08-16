

22//199侧面观察二叉树（二叉树宽搜——层次遍历）

vector<int> rightSideView(TreeNode* root)
{
	//层序遍历二叉树，保存最右边的数字
	vector<int> res;
	if(root==NULL)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty())
	{
		res.push_back(q.back()->val);
		for(int i=0;i<q.size();++i)
		{
			TreeNode* p=q.front();q.pop();
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
		}
	}
	return res;
}

