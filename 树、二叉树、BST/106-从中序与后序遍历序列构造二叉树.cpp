

15//106从中序与后序遍历序列构造二叉树

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{	
	if(inorder.size()==0)
		return NULL;	
	return make(postorder.begin(),postorder.end(),inorder.begin(),inorder.end());
}


template <typename Iter>
TreeNode *make(Iter pFirst, Iter pLast, Iter iFirst, Iter iLast)
{
    if(pFirst==pLast) return NULL;
    if(iFirst==iLast) return NULL;
    
    int val=*(pLast-1);
    TreeNode *node=new TreeNode(val);
    
    auto ival=find(iFirst, iLast, val);
    
    int length=ival-iFirst;
    
    node->left=make(pFirst, pFirst+length, iFirst, ival);
	node->right=make(pFirst+length, pLast-1, ival+1, iLast);
    
    return node;
}
