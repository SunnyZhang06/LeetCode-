/*
* @author：sunny
* 387、字符串中的第一个唯一字符
* https://leetcode-cn.com/problems/first-unique-character-in-a-string/
* 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
*/

/*
* 方法1：用HashMap建立字符到出现次数的映射
* 思路：用哈希表建立每个字符和其出现次数的映射，然后按顺序遍历字符串
*       找到第一个出现次数为1的字符，返回其位置即可。
*/

int firstUniqChar(string s) 
{
	unordered_map<char,int> m;
	for(char c:s)
		++m[c];

	for(int i=0;i<s.size();++i)
	{
		if(m[s[i]]==1)
			return i;
	}
	return -1;		
}