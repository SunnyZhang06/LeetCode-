//二叉树的三种常见遍历顺序（先序、中序、后序）有三种写法(递归，非递归，Morris遍历)
//二叉树的层序遍历也有递归和非递归解法，要熟练掌握

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}


	
2//94二叉树的中序遍历

//递归
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> res;
	helper(root,res);
	return res;
}
void helper(TreeNode* root,vector<int>& res)
{
	if(root==NULL)
		return;
	if(root->left!=NULL)
		helper(root->left,res);
	res.push_back(root->val);
	if(root->right!=NULL)
		helper(root->right,res);
}

//迭代（借助栈）

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> st;
	TreeNode* p=root;
	
	while(!s.empty() || p!=NULL)
	{
		if(p)
		{
			st.push(p);//先把所有左子节点压入栈中
			p=p->left;
		}
		else
		{
			p=st.top();
			st.pop();
			res.push_back(p->val);
			p=p->right;
		}
	}
	return res;
	
}
