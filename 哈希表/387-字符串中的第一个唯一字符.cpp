
11//387字符串中的第一个唯一字符

int firstUniqChar(string s) 
{
	//用哈希表建立每个字符和其出现次数的映射，然后按顺序遍历字符串
	//找到第一个出现次数为1的字符，返回其位置即可
	unordered_map<char,int> m;
	for(char c:s)
		++m[c];
	/*遍历
	unordered_map<char, int>::iterator i;
	for (i = m.begin(); i != m.end(); i++)
	   cout << i->first << " " << i->second << endl;
   */
	for(int i=0;i<s.size();++i)
	{
		if(m[s[i]]==1)
			return i;
	}
	return -1;
		
}