/*
* @author：sunny
* 290、词语模式（字符串哈希）
* https://leetcode-cn.com/problems/word-pattern/
* 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
*/

/*
* 方法1：用HashMap建立模式字符串中每个字符和单词字符串中每个单词之间的映射
* 思路：在碰到一个新字符时，首先检查其是否在HashMap中出现，若出现，其映射的单词
*       若不是此时对应的单词，则返回false。如果没有在HashMap中出现，我们还要遍历一遍HashMap，
*       看新遇到的单词是否已经是其中的映射，若已经有其他映射，直接返回false，如果没有，
*       再更新遇到的字符建立映射。(本题相当于key和value都给你提供了，然后要自己建立hashmap)
*/

bool wordPattern(string pattern, string str) 
{
	int i=0,n=pattern.size();
	unordered_map<char,string> m;
	istringstream in(str);
	
	for(string word;in>>word;++i)
	{
		if(m.count(pattern[i]))//key出现过
		{
			if(m[pattern[i]]!=word)//同key不同value,false
				return false;			
		}
		else
		{
			for(auto a:m)
			{
				if(a.second==word)//key没出现过(不同key同value,false)
					return false;
			}
			m[pattern[i]]=word;			
		}
	}
	return i==n;	
}

/*
* 方法2：用两个HashMap来完成，分别建立字符和单词字符串到它们出现位置的映射。
* 思路：分别将字符和单词都映射到当前的位置加1(避免默认映射值0),在遇到新字符和单词时，
*       首先看 i 是否已经是 n 了，若相等了，说明此时pattern中的字符已经用完了，
*       而str中还有多余的单词，这样是无法建立一对一映射的，直接返回false,还有当两个HashMap的
*       映射值不相同时也返回false，否则我们同时建立单词和pattern字符和当前位置加1之间的映射
*/

bool wordPattern(string pattern, string str) 
{
	unordered_map<char,int> m1;
	unordered_map<string,int> m2;
	istringstream in(str);
	int i=0,n=pattern.size();
	
	for(string word;in>>word;++i)
	{
		if(i==n||m1[pattern[i]]!=m2[word])
			return false;
		m1[pattern[i]]=m2[word]=i+1;
	}
	return i==n;	
}