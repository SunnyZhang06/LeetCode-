

4//205同构字符串

bool isIsomorphic(string s, string t) 
{	
	//记录字符出现的位置，遍历两个字符串时，分别在两个哈希表中查找其值，不能则返回false
	int m=s.size(),n=t.size();
	if(m!=n)
		return false;
	unordered_map<char,int> m1;
	unordered_map<char,int> m2;

	for(int i=0;i<m;++i)
	{
		if(m1[s[i]]!=m2[t[i]])
			return false;
		m1[s[i]]=i+1;
		m2[t[i]]=i+1;
	}
	return true;
	
	//用数组代替哈希表
	int m1[256]={0},m2[256]={0},n=s.size();
	
	for(int i=0;i<n;++i)
	{
		if(m1[s[i]]!=m2[t[i]])
			return false;
		m1[s[i]]=i+1;
		m2[t[i]]=i+1;
	}
	return true;
}
