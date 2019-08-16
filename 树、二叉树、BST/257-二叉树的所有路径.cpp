
25//257二叉树的所有路径

vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> res;
	if(root==NULL)
		return res;
	
	if(root->left==NULL && root->right==NULL)
		res.push_back(to_string(root->val));
	
	vector<string> lefts=binaryTreePaths(root->left);
	for(int i=0;i<lefts.size();++i)
		res.push_back(to_string(root->val)+"->"+lefts[i]);
	
	vector<string> rights=binaryTreePaths(root->right);
	for(int i=0;i<rights.size();++i)
		res.push_back(to_string(root->val)+"->"+rights[i]);
	
	return res;
}

