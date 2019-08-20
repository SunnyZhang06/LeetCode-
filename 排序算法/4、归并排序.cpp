/*
* @author：sunny
* 459、重复的子字符串
* https://leetcode-cn.com/problems/repeated-substring-pattern/
* 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
*/	

/*
* 思路：既然能拆分成多个子串，那么每个子串的长度肯定不能大于原字符串长度的一半，那么可以从原字符串长度的一半遍历到1，
*   如果当前长度能被总长度整除，说明可以分成若干个子字符串，然后将这些子字符串拼接起来看跟原字符串是否相等。 如果拆完了都不相等，返回false。
*/

 bool repeatedSubstringPattern(string s) 
 {
	int n=s.size();
	for(int i=n/2;i>=1;i--)//从1~n/2长度的字串开始，找长度能被总长度整除的字串
	{
		if(n%i==0)
		{
			int c=n/i;//由子串重复c次构成
			string t="";
			for(int j=0;j<c;j++)
				t+=s.substr(0,i);
			if(s==t)
				return true;
		}            
	}
	return false;         
 }





