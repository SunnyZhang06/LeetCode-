
21//114二叉树转链表（二叉树与链表）

void flatten(TreeNode* root) {
	
	//利用DFS的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上
	//父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作
	/*递归
	if(root==NULL)
		return ;
	if(root->left)
		flatten(root->left);
	if(root->right)
		flatten(root->right);
	TreeNode* tmp=root->right;
	root->right=root->left;
	root->left=NULL;
	while(root->right)
		root=root->right;
	root->right=tmp;
	*/
	
	//迭代：从根节点开始出发，先检测其左子结点是否存在，如存在则将根节点和其右子节点断开，
	//将左子结点及其后面所有结构一起连到原右子节点的位置，把原右子节点连到元左子结点最后面的右子节点之后
	TreeNode *cur = root;
	while (cur) 
	{
		if (cur->left) 
		{
			TreeNode *p = cur->left;
			while (p->right) p = p->right;
			p->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		cur = cur->right;
	}
	
}

//线索二叉树

//剑指offer36二叉搜索树与双向链表

TreeNode* convertNode(TreeNode* root)
{
	TreeNode* pLast=NULL;//指向已经转换好的链表的最后一个结点（值最大的点）
	convert(root,&pLast);
	
	TreeNode* pHead=pLast;
	while(pHead!=NULL && pHead->left!=NULL)
		pHead=pHead->left;
	return pHead;
}

void convert(TreeNode* root,TreeNode** pLast)
{
	if(root==NULL)
		return ;
	TreeNode* cur=root;
	if(cur->left!=NULL)
		convert(cur->left,pLast);
	cur->left=*pLast;
	
	if(*pLast!=NULL)
		(*pLast)->right=cur;
	*pLast=cur;//把根节点和左子树转换后的链表连起来，然后更新根节点（当前节点）为链表尾结点
	
	if(cur->right!=NULL)
		convert(cur,right,pLast);
	
}

