/*
* @author：sunny
* 14、最长公共前缀
* https://leetcode-cn.com/problems/longest-common-prefix/
* 编写一个函数来查找字符串数组中的最长公共前缀。
*/	

/*
* 思路1：以第一个字符串为基准，逐个字符判断，如["flower","flow","flight"]，以"flower"为基准，逐个字符‘f’、‘l’...去判断。
*/

string longestCommonPrefix(vector<string>& strs)
{
	if(strs.empty())
		return "";
	string res="";	
	for(int j=0;j<strs[0].size();++j)
	{
		char c=strs[0][j];//第一个字符串的第j个字符
		for(int i=1;i<strs.size();++i)
		{
			if(j>=strs[i].size() || strs[i][j]!=c)//注意字符串长度问题
				return res;
		}
		res.push_back(c);
	}
	return res;	
}

/*
* 思路2：对上面的方法进行如下优化：如果发现当前某个字符和第一个字符串对应位置的字符不相等，说明不会再有更长的共同前缀了，直接通过用substr的方法直接取出共同前缀的子字符串。
*   如果遍历结束前没有返回结果的话，说明第一个单词就是公共前缀，返回为结果即可。
*/

string longestCommonPrefix(vector<string>& strs)
{	
	if(strs.empty())
		return "";
	/*以第一个为基准，逐个字符判断*/
	for(int j=0;j<strs[0].size();++j)
	{
		char c=strs[0][j];//第一个字符串的第j个字符
		for(int i=1;i<strs.size();++i)
		{
			if(j>=strs[i].size() || strs[i][j]!=c)
				return strs[0].substr(0,j);
		}		
	}
	return strs[0];	
}

/*
* 思路3：如果按字母顺序排序,有共同字母多的两个字符串会被排到一起，而跟大家相同的字母越少的字符串会被挤到首尾两端
*   那么如果有共同前缀的话，一定会出现在首尾两端的字符串中，所以我们只需要找首尾字母串的共同前缀即可。
*/

string longestCommonPrefix(vector<string>& strs)
{	
	if(strs.empty())
		return "";
	sort(strs.begin(),strs.end());
	int i=0,len=min(strs[0].size(),strs.back().size());
	while(i<len && strs[0][i]==strs.back()[i])
		++i;
	return strs[0].substr(0,i);
}