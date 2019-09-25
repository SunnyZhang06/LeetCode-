

19//235二叉搜索树的最近公共祖先

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{	
	//根据二叉搜索树的性质，左<根<右
	/*
	if(root==NULL)
		return root;
	if(root->val > max(p->val,q->val))
		return lowestCommonAncestor(root->left,p,q);
	else if(root->val < min(p->val,q->val))
		return lowestCommonAncestor(root->right,p,q);
	else
		return root;
		*/
		
	//非递归写法
	while(true)
	{
		if(root->val > max(p->val,q->val))
			root=root->left;
		else if(root->val < min(p->val,q->val))
			root=root->right;
		else
			break;
	}
	return root;     
	
}

vector<string> res;
for(int a=1;i<4;++a)
{
	for(int b=1;b<4;b++)
	{
		for(int c=1;c<4;c++)
		{
			for(int d=1;d<4;d++)
			{
				if(a+b+c+d==s.size())
				{
					int A=stoi(s.substr(0,a));
					int B=stoi(s.substr(a,b));
					int B=stoi(s.substr(a+b,c));
					int B=stoi(s.substr(a+b+c,d));
					if(A<=255 && B<=255 && C<=255 && D<=255)
					{
						string t=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D);
						if(t.size()==s.size()+3)
							res.push_back(t);
					}
					
				}
			}
		}
	}
	return res;
}

void restore(string s,int k,string out,vector<string> &res)
{
	if(k==0)
	{
		if(s.empty())
			res.push_back(out);
	}
	else
	{
		for(int i=1;i<=3;++i)
		{
			if(s.size()>=i && isValid(s.substr(0,i)))
			{
				if(k==1)
					restore(s.substr(i),k-1,out+s.substr(0,i),res);
				else
					restore(s.substr(i),k-1,out+s.substr(0,i)+".",res);
				
			}
		}
	}
}

bool isVaild(string s)
{
	if(s.empty()||s.size()>3||(s.size()>1&&s[0]=='0'))
		return false;
	int res=atoi(s.c_str());
	return res<=255 && res>=0;
}
