/*
* @author：sunny
* 58、最后一个单词的长度
* https://leetcode-cn.com/problems/length-of-last-word/
* 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
*/	

/*
* 思路1：将字符串翻转后去掉开头的空格，然后到第二个空格前判断字符串的长度即可
*/

int lengthOfLastWord(string s)
{
	int i=0,res=0,n=s.zie();
	reverse(s.begin(),s.end());
	while(s[i]==' ')
		++i;
	while(i<n && str[i++]!=' ')
		++res;
	return res;	
}


/*
* 思路2：用istringstream类(作用是从string对象str中读取字符，用空格作为字符串分隔符，头文件sstream)，把每个单词读出来并判断长度，然后返回最后一个长度即可。
*/

int lengthOfLastWord(string s)
{
	istringstream is(s);
	string str;
	int cnt=0;
	while(is>>str)
		cnt = str.size();
	return cnt;
}