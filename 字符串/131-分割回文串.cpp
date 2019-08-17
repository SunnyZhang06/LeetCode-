/*
* @author：sunny
* 131、分割回文串
* https://leetcode-cn.com/problems/reverse-words-in-a-string/
* 给定一个字符串，逐个翻转字符串中的每个单词。
*/	

/*
* 思路：
*/

*8//131分割回文串

//深度优先
 vector<vector<string>> partition(string s)
 {
	 vector<vector<string>> res;
	 vector<string> out;
	 helper(s,0,out,res);
	 return res;
 }
 
 void helper(string s,int start, vector<string>& out,vector<vector<string>>& res)
 {
	 if(start==s.size())
	 {
		 res.push_back(out);
		 return ;
	 }
	 for(int i=start;i<s.size();++i)
	 {
		 if(!isPalindrome(s,start,i))
			 continue;
		 out.push_back(s.substr(start,i-start+1));
		 helpers(s,i+1,out,res);
		 out.pop_back();
	 }
 }
 
 //是否为回文串
 bool isPalindrome(string s,int start, int end)
 {
	 while(start<end)
	 {
		 if(s[start]!=s[end])
			 return false;
		 ++start;
		 --end;
	 }
	 return true;
 }







