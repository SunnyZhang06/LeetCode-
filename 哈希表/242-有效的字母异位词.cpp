
2//242有效的字母异位词
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词

bool isAnagram(string s, string t) {
	
	//按字母大小排序后比较是否一样
	/*O(N*logN)
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());        
	return s==t;
	*/
	
	//map统计每个字符出现的次数，{letter：count}
	map<char,int> m1;
	map<char,int> m2;
	//for(int i=0;i<s.size();++i)
	//	++m1[s[i]];
	//for(int i=0;i<t.size();++i)
	//	++m2[t[i]];
	for(char c:s) ++m1[c];
	for(char c:t) ++m2[c];
	return m1==m2;
	
	
	//用数组代替哈希表，26个字母对应长度为26的数组
	if(s.size()!=t.size())
		return false;
	int m[26]={0};
	for(char c:s) ++m[c-'a'];
	
	for(char c:t)
	{
		if(--m[c-'a']<0)
			return false;
	}
	return true;
	
}

