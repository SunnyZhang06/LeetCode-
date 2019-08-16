

16//110平衡二叉树

bool isBalanced(TreeNode* root)
{
	//时间复杂度O(N*lgN),每一个点都会被上面的点计算深度时访问一次
	if(root==NULL)
		return true;
	if(abs(Depth(root->left)-Depth(root->right))>1)
		return false;
	return isBalanced(root->left)&&isBalanced(root->right);
}

int Depth(TreeNode* root)
{
	if(root==NULL)
		return 0;
	int left=Depth(root->left)+1;
	int right=Depth(root->right)+1;
	return max(left,right);
}

//优化思路:如果我们发现子树不平衡，则不计算具体的深度，而是直接返回-1。
//对于每一个节点，我们通过checkDepth方法递归获得左右子树的深度，
//如果子树是平衡的，则返回真实的深度，若不平衡，直接返回-1，此方法时间复杂度O(N)，空间复杂度O(H)，
bool isBalanced(TreeNode *root) 
{
	if (checkDepth(root) == -1) return false;
	else return true;
}
int checkDepth(TreeNode *root) 
{
	if (!root) return 0;
	int left = checkDepth(root->left);
	if (left == -1) return -1;
	int right = checkDepth(root->right);
	if (right == -1) return -1;
	int diff = abs(left - right);
	if (diff > 1) return -1;
	else return 1 + max(left, right);
}