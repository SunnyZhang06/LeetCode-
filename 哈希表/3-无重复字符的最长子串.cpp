1//3无重复字符的最长子串

int lengthOfLongestSubstring(string s)
{
	//使用HashMap来建立字符和其出现位置之间的映射
	//维护一个滑动窗口，窗口内的都是没有重复的字符，我们需要尽可能的扩大窗口的大小。
	int res=0,left=-1,n=s.size();	
	unordered_map<int, int> m;
	for(int i=0;i<n;++i)
	{
		if(m.count(s[i])&&m[s[i]]>left)//如果曾经出现过，更新窗口左边界
		{
			left=m[s[i]];
		}
		m[s[i]]=i;//建立字符和其出现位置之间的映射（重复字符保存最后出现位置）
		res=max(res,i-left);//右边界就是当前遍历到的字符,窗口的大小为i-left
	}
	return res;
}