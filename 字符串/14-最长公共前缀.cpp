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
*2//5最长回文子串

string longestPalindrome(string s)
{

}

3//8字符串转换整数 (atoi)

int myAtoi(string str) 
{
	if(str.empty())
		return 0;
	int sign=1,base=0,i=0,n=str.size();
	
	while(i<n && str[i]==' ')//判断空格
		++i;
	
	if(i<n && (str[i]=='+'||str[i]=='-'))//判断符号
	{
		sign = (str[i++]=='+')?1:-1;
	}
	
	while(i<n && str[i]>='0' && str[i]<='9')//如果第一个字符不是数字，返回0，否则转为整型保存下来
	{
		if(base>INT_MAX/10 || (base==INT_MAX/10 && str[i]-'0'>7))
			return sign==1?INT_MAX:INT_MIN;
		base = 10*base+str[i++]-'0';
	}
	return sign*base;
}

4//10正则表达式匹配

5//14最长公共前缀

string longestCommonPrefix(vector<string>& strs)
{
	if(strs.empty())
		return "";
	string res="";
	
	//以第一个为基准，逐个字符判断
	for(int j=0;j<strs[0].size();++j)
	{
		char c=strs[0][j];//第一个字符串的第j个字符
		for(int i=1;i<strs.size();++i)
		{
			if(j>=strs[i].size() || strs[i][j]!=c)
				return res;
		}
		res.push_back(c);
	}
	return res;	
	
	//如果我们发现当前某个字符和第一个字符串对应位置的字符不相等，
	//说明不会再有更长的共同前缀了，我们直接通过用substr的方法直接取出共同前缀的子字符串。
	//如果遍历结束前没有返回结果的话，说明第一个单词就是公共前缀，返回为结果即可。
	if(strs.empty())
		return "";
	//以第一个为基准，逐个字符判断
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
	
	
	//按字母顺序排序,有共同字母多的两个字符串会被排到一起，而跟大家相同的字母越少的字符串会被挤到首尾两端
	//那么如果有共同前缀的话，一定会出现在首尾两端的字符串中，所以我们只需要找首尾字母串的共同前缀即可。
	if(strs.empty())
		return "";
	sort(strs.begin(),strs.end());
	int i=0,len=min(strs[0].size(),strs.back().size());
	while(i<len && strs[0][i]==strs.back()[i])
		++i;
	return strs[0].substr(0,i);
}

6//58最后一个单词的长度

int lengthOfLastWord(string s)
{
	int i=0,res=0,n=s.zie();
	reverse(s.begin(),s.end());//将字符串翻转
	while(s[i]==' ')//去掉开头的空格
		++i;
	while(i<n && str[i++]!=' ')
		++res;
	return res;
	
}

7//125验证回文串

bool isPalindrome(string s)
{
	//左右两边同时扫描，遇到空格和标点跳过，遇到大写字母转换为小写
	int left=0,right=s.size()-1;
	while(left<right)
	{
		if(!isalnum(s[left]))//跳过空格和标点
			++left;
		else if(!isalnum(s[right]))
			--right;
		else if((s[left]+32-'a')%32 != (s[right]+32-'a')%32)
			return false;                
		else
		{
			++left;
			--right;
		}                
	}
	return true;
	
	//直接处理字符串
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

 *9//139单词拆分
//动态规划


10//344翻转字符串

void reverseString(vector<char>& s)
{
	int size=s.size();
	int p1=0,p2=size-1;
	
	while(p1<p2)
	{
		swap(s[p1],s[p2]);
		p1++;
		p2--;
	}
	
	//
	int len = s.size();
	int j = len - 1;
	for (int i = 0; i < len / 2; i++)
	{
		swap(s[i], s[j]);
		j--;
	}
}

11//387字符串中的第一个唯一字符

int firstUniqChar(string s) 
{
	//用哈希表建立每个字符和其出现次数的映射，然后按顺序遍历字符串
	//找到第一个出现次数为1的字符，返回其位置即可
	unordered_map<char,int> m;
	for(char c:s)
		++m[c];
	/*遍历
	unordered_map<char, int>::iterator i;
	for (i = m.begin(); i != m.end(); i++)
	   cout << i->first << " " << i->second << endl;
   */
	for(int i=0;i<s.size();++i)
	{
		if(m[s[i]]==1)
			return i;
	}
	return -1;
		
}

12//459重复的子字符串

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





