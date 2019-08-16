/*
* @author：sunny
* 3、无重复字符的最长子串
* https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度，
* 如 "abcabcbb" ，无重复字符的最长子串是 "abc"，所以其长度为 3。
*/

/*
* 方法1：使用HashMap来建立字符和其最后出现位置之间的映射
* 思路：维护一个滑动窗口，窗口内的都是没有重复的字符，我们需要尽可能的扩大窗口的大小。
*       用变量res记录最长无重复字串的长度，left指向无重复子串左边的起始位置的前一个（窗口左边界）
*       根据遍历字符串时字符是否出现过更新left的值，然后计算窗口长度，更新res值。
*/

int lengthOfLongestSubstring(string s)
{
	int res=0,left=-1,n=s.size();	
	unordered_map<int, int> m;
	for(int i=0;i<n;++i)
	{
		if(m.count(s[i])&& m[s[i]]>left)//如果曾经出现过，更新窗口左边界
		{
			left=m[s[i]];
		}
		m[s[i]]=i;//建立字符和其出现位置之间的映射（重复字符保存最后出现位置）
		res=max(res,i-left);//右边界就是当前遍历到的字符,窗口的大小为i-left
	}
	return res;
}

/*
* 方法2：建立一个 256 位大小的整型数组来代替 HashMap
* 思路：这样做的原因是 ASCII 表共能表示 256 个字符，但是由于键盘只能表示 128 个字符，所以用 128 也行
*       然后全部初始化为 -1，对于每一个遍历到的字符，直接用其在数组中的值来更新 left，因为默认是 -1，
*       而 left 初始化也是 -1，这样就省了 if 判断的步骤，其余思路都一样。
*/

int lengthOfLongestSubstring(string s)
{
	int left=-1,res=0;
	vector<int> m(128,-1);
	
	for(int i=0;i<s.size();++i)
	{
		left = max(left,m[s[i]]);
		m[s[i]] = i;
		res = max(res,i-left);
	}
	return res;
}
