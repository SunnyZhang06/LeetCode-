

12//100相同的树

bool isSameTree(TreeNode* p, TreeNode* q)
{
	//递归
	if(p==NULL && q==NULL)
		return true;
	if(p==NULL || q==NULL)
		return false;
	if(p->val ==q->val)
		return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
	return false;
	
	//迭代
	stack<TreeNode*> s;
	s.push(p);
	s.push(q);
	
	while(!s.empty())
	{
		p=s.top();s.pop();//同进同出
		q=s.top();s.pop();
		
		if(!p && !q)
			continue;
		if(!p || !q)
			return false;
		if(p->val != q->val)
			return false;
		
		s.push(p->left);
		s.push(q->left);
		
		s.push(p->right);
		s.push(q->right);
	}
	return true;
}
