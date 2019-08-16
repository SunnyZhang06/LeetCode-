
20//236最近的公共祖先（二叉树性质）

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{	
	if(!root || p==root|| q==root)
		return root;
	TreeNode* left=lowestCommonAncestor(root->left, p, q);;//左子树中找
	TreeNode* right=lowestCommonAncestor(root->right, p, q);;//右子树中找
	if(left && right)//都找到了，则返回根节点
		return root;
	return left?left:right;//要么在左子树中，要么右子树中
	
	//进行优化:如果当前结点不为空，且既不是p也不是q，那么根据上面的分析，p和q的位置就有三种情况，
	//p和q要么分别位于左右子树中，要么同时位于左子树，或者同时位于右子树。
	//需要优化的情况就是当p和q同时为于左子树或右子树中，而且返回的结点并不是p或q，
	//那么就是p和q的最小父结点了，已经求出来了，就不用再对右结点调用递归函数了
	
	if (!root || p == root || q == root) 
		return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	if (left && left != p && left != q) 
		return left;
	TreeNode *right = lowestCommonAncestor(root->right, p , q);
　　　　 if (left && right)  
		return root;
	return left ? left : right;
	
}
