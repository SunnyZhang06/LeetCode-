//二叉树的三种常见遍历顺序（先序、中序、后序）有三种写法(递归，非递归，Morris遍历)
//二叉树的层序遍历也有递归和非递归解法，要熟练掌握

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

1//144二叉树的前序遍历

//递归
vector<int> preorderTraversal(TreeNode* root) 
{
	vector<int> res;
	helper(root,res);
	return res;
}

void helper(TreeNode* root,vector<int>& res)
{
	if(root==NULL)
		return;
	res.push_back(root->val);
	if(root->left!=NULL)
		helper(root->left,res);
	if(root->right!=NULL)
		helper(rot->right,res);
}

//迭代（借助栈）

vector<int> preorderTraversal(TreeNode* root)
{
	//根节点先入栈，循环中先保存根节点的值，然后依次把根节点的右孩子、左孩子压入栈
	vector<int> res;
	stack<TreeNode*> st;
	if(root==NULL);
		return res;
	st.push(root);//根节点人栈
	
	while(!st.empty())
	{
		TreeNode* t=st.top();st.pop();
		res.push_back(t->val);
		if(t->right!=NULL)
			st.push(t->right);
		if(t->left!=NULL)
			st.push(t->right);		
	}
	return res;
}
