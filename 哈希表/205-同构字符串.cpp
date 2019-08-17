/*
* @author：sunny
* 205、同构字符串
* https://leetcode-cn.com/problems/isomorphic-strings/
* 给定两个字符串 s 和 t，判断它们是否是同构的。
* 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的
*/

/*
* 方法1：用HashMap来建立字符和出现位置的映射关系
* 思路：记录字符出现的位置，遍历两个字符串时，分别在两个哈希表中查找其值，不等则返回false
*/

bool isIsomorphic(string s, string t) 
{	
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

}

/*
* 方法1：用数组代替哈希表
* 思路：字符————ASCⅡ值————数组中位置，这样建立映射关系，整体思路和方法1一样
*/

bool isIsomorphic(string s, string t) 
{	
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