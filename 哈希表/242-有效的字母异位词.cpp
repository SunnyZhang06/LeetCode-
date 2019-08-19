/*
* @author：sunny
* 242、有效的字母异位词
* https://leetcode-cn.com/problems/valid-anagram/
* 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
*/

/*
* 方法1：排序后比较是否相等
* 思路：对两个字符串排序，排序后安字母大小顺序排列直接进行比较机即可，复杂度O(N*lgN)。
*/

bool isAnagram(string s, string t) 
{
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());        
	return s==t;
}

/*
* 方法2：用HashMap建立字符到出现次数的映射
* 思路：使用两个map分别统计s和t中每个字符出现的次数，{letter：count}，然后比较两个map是否相同即可
*/

bool isAnagram(string s, string t) 
{
	map<char,int> m1;
	map<char,int> m2;
	for(char c:s) ++m1[c];
	for(char c:t) ++m2[c];
	return m1==m2;	
}
/*
* 方法3：用数组代替哈希表
* 思路：26个字母对应长度为26的数组，其他思路和使用HashMap一样。
*/

bool isAnagram(string s, string t) 
{
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