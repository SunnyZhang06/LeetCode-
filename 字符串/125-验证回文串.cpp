/*
* @author：sunny
* 125、验证回文串
* https://leetcode-cn.com/problems/valid-palindrome/
* 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写
*/	

/*
* 思路1：左右两边同时扫描，遇到空格和标点跳过，遇到大写字母转换为小写。这里用isalnum库函数判断字符变量c是否为字母或数字，若是则返回非零，否则返回零。
*/

bool isPalindrome(string s)
{
	int left=0,right=s.size()-1;
	while(left<right)
	{
		if(!isalnum(s[left]))//跳过空格和标点
			++left;
		else if(!isalnum(s[right]))
			--right;
		else if((s[left]+32-'a')%32 != (s[right]+32-'a')%32)//如果是字符先大小写转换再判断
			return false;                
		else
		{
			++left;
			--right;
		}                
	}
	return true;
}

/*
* 思路2：遍历一遍字符串，把空格和标点全部去掉，大写转换为小写，变成只含纯小写字母的字符串，然后将翻转前字符串和翻转后对比即可。
*/

bool isPalindrome(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(!isalnum(s[i]))//如果是空格和标点则删除
		{
			str.erase(i,1);
			i--;
		}	
		else if(s[i]>='A'&& s[i]<='Z')//如果是大写则转换为小写
			s[i]+=32;
	}
	string s1=s;
    reverse(s.begin(),s.end());        
    return s==s1;
}

