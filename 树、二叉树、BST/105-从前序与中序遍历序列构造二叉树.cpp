
14//105从前序与中序遍历序列构造二叉树

//前序：根-左-右	中序：左-根-右
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if(preorder.size()==0)
		return NULL;
	return make(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
}

template <typename Iter>
TreeNode *make(Iter pFirst, Iter pLast, Iter iFirst, Iter iLast)
{
    if(pFirst==pLast) return NULL;
    if(iFirst==iLast) return NULL;
    
    int val=*pFirst;
    TreeNode *node=new TreeNode(val);
    
    auto ival=find(iFirst, iLast, val);
    
    int leftLength=ival-iFirst;
    
    node->left = make(pFirst+1, pFirst+leftLength+1, iFirst, ival);
    node->right = make(pFirst+leftLength+1, pLast, ival+1, iLast);
    
    return node;
}

