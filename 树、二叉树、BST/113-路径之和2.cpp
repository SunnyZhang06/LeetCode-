

18//113路径之和2（二叉树深搜）——找出所有路径

//用深度优先搜索DFS，只不过数据结构相对复杂一点，需要用到二维的vector，而且每当DFS搜索到新节点时，都要保存该节点。
//而且每当找出一条路径之后，都将这个保存为一维vector的路径保存到最终结果二位vector中。并且，每当DFS搜索到子节点，
//发现不是路径和时，返回上一个结点时，需要把该节点从一维vector中移除
vector<vector<int>> pathSum(TreeNode* root, int sum) 
{        
	vector<vector<int>> result;
	vector<int> cur;//中间结果
	pathSum(root,sum,cur,result);
	return result;
}

void pathSum(TreeNode* root,int sum,vector<int> &cur,vector<vector<int>> &res)
{
	if(root==NULL)
		return ;
	cur.push_back(root->val);
	if(root->left==NULL && root->left==NULL && root->val==sum)//叶节点
		res.push_bakc(cur);
	pathSum(root->left,sum-root->val,cur,res);
	pathSum(root->right,sum-root->right,cur,res);
	cur.pop_back();
}

//找出到达某个结点的路径？
