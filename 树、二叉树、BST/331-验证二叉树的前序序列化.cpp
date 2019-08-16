
//331验证二叉树的前序序列化
bool isValidSerialization(string preorder)
{
	istringstream in(preorder);//用preorder初始化字符串输入流对象(包含sstream头文件)
	vector<string> v;
	int cnt=0;
	string t;
	while(getline(in,t,','))
		v.push_back(t);//把每个字符（包括#）保存到vector中
	//1. 数字的个数总是比#号少一个
	//2. 最后一个一定是#号
	
	for(int i=0;i<v.size();++i)
	{
		if(v[i]=="#")
		{
			if(cnt==0)
				return false;
			cnt--;			
		}
		else
			cnt++;
	}	
	return cnt==0 && v.back()=="#";
	
}












