
23//226翻转二叉树（镜像二叉树）

TreeNode* invertTree(TreeNode* root)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right==NULL)
		return root;
	
	TreeNode* tmp=root->left;
	root->left=root->right;
	root->right=tmp;
	
	if(root->left)
		invertTree(root->left);
	if(root->right)
		invertTree(root->right);
	return root;
	
	//
	if(root)
	{
		TreeNode *newleft=NULL;
		TreeNode *newright=NULL;
		
		if(root->left)
			newleft=invertTree(root->left);
		if(root->right)
			newright=invertTree(root->right);
		
		root->left=newright;
		root->right=newleft;
	}
	return root; 
	
	//
	if (!root) return NULL;
	TreeNode *tmp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(tmp);
	return root;	
}

//迭代法：
TreeNode* invertTree(TreeNode* root) 
{
	if (!root) return NULL;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *node = q.front(); q.pop();
		TreeNode *tmp = node->left;
		node->left = node->right;
		node->right = tmp;
		if (node->left) q.push(node->left);
		if (node->right) q.push(node->right);
	}
	return root;
}
