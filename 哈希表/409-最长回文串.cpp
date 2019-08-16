

7//409最长回文串（字符哈希）

int longestPalindrome(string s) 
{	
	//通过哈希表来建立字符和其出现次数的映射{letter:count}
	//统计出来所有偶数个字符的出现总和，然后如果有奇数个字符的话，取出其最大偶数，然后最后结果加1
	/*
	int res=0;
	bool mid=false;
	unordered_map<char,int> m;
	for(char c:s)
		++m[c];//统计所有字符出现的次数
	for(auto it=m.begin();it!=m.end();++it)
	{
		res+=it->second;
		if(it->second%2==1)//出现奇数次
		{
			res-=1;//减去1变成偶数(0 2 4 6...)
			mid=true;
		}
	}
	return mid?res+1:res;
	*/
	
	//找出有奇数个的字符:使用一个set集合，如果遍历到的字符不在set中，那么就将其加入set，
	//如果已经在set里了，就将其从set中删去，这样遍历完成后set中就是所有出现个数是奇数个的字符了
	unordered_set<char> t;
	for(char c:s)
	{
		if(!t.count(c))
			t.insert(c);
		else
			t.erase(c);
	}
	//如果没有奇数个的字符，t.size()=0,t.size()-1代表不能用的
	//如“aaabbbbbccc”,t.size()=3说明字符为奇数个的有3个a,b,c，减去1说明可以选其中一个做为回文串中心，剩下的不能用
	return s.size()-max(0,(int)t.size()-1);
}