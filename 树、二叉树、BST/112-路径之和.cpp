

17//112路径之和

bool hasPathSum(TreeNode* root, int sum)
{
	//递归法
	if(root==NULL)
		return false;
	if(root->left==NULL && root->right==NULL)
		return sum==root->val;
	if(root->left)
		if(hasPathSum(root->left,sum-root->val))
			return true;
	if(root->right)
		if(hasPathSum(root->right,sum-root->val))
			return true;
	return false;
	
	 //迭代法
	//先序遍历二叉树，左右子结点都需要加上其父结点值，这样当遍历到叶结点时，
	//如果和sum相等了，那么就说明一定有一条从root过来的路径
	if (root==NULL) 
		return false;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty()) {
		TreeNode *t = st.top(); st.pop();
		if (!t->left && !t->right) {
			if (t->val == sum) return true;
		}
		if (t->right) {
			t->right->val += t->val;
			st.push(t->right);
		}
		if (t->left) {
			t->left->val += t->val;
			st.push(t->left);
		}
	}
	return false;
}