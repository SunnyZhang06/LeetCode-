

24//230二叉搜索树中第K小的元素

int kthSmallest(TreeNode* root, int k)
{
	//递归：中序遍历
	return inOrder(root,k);
	
	//非递归中序遍历，用cnt计数，每遍历一个结点，计数器自增1
	int cnt=0;
	stack<TreeNode *> s;
	TreeNode *p=root;
	
	while(p || !s.empty())
	{
		while(p)
		{
			s.push(p);
			p=p->left;
		}
		p=s.top();s.pop();
		cnt++;
		
		if(cnt==k) return p->val;
		
		p=p->right;
	}
	
	return 0; 
	
}

int inOrder(TreeNode* root, int k)
{
	if(root==NULL)
		return -1;
	int val=inOrder(root->left,k);
	if(k==0)
		return val;
	if(--k==0)
		return root-val;
	return inOrder(root->right,k);
	
}

//分治解法：根据BST的性质，可以快速定位出第k小的元素是在左子树还是右子树，
//首先计算出左子树的结点个数总和cnt，如果k小于等于左子树结点总和cnt，说明第k小的元素在左子树中，
//直接对左子结点调用递归即可。如果k大于cnt+1，说明目标值在右子树中，对右子结点调用递归函数，
//注意此时的k应为k-cnt-1，应为已经减少了cnt+1个结点。如果k正好等于cnt+1，说明当前结点即为所求
int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (k <= cnt) {
            return kthSmallest(root->left, k);
        } else if (k > cnt + 1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
	
int count(TreeNode* node) {
	if (!node) return 0;
	return 1 + count(node->left) + count(node->right);//结点个数
}
