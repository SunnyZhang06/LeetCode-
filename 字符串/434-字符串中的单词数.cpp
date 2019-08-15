/*
* @author：sunny
* 459、重复的子字符串
* https://leetcode-cn.com/problems/number-of-segments-in-a-string/
* 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
*/	

/*
* 思路1：用istringstream类，以空格作为字符串分隔符，分割的同时计数，最终返回计数结果即可。(小问题是分割时标点符号会跟在单词后面算作一个字符串) 
*/

int countSegments(string s) 
{	
	int res=0;
	istringstream is(s);
	string str;
	while(is>>str)
		res++;
	return res;	
	
	/*另外一种写法*/
	/*
	int res = 0;
	istringstream is(s);
	string t = "";
	while (getline(is, t, ' ')) {//利用getline函数取出每两个空格符之间的字符串
		if (t.empty()) continue;
		++res;
	}
	return res;
	*/
}

/*
* 思路2：遍历字符串，遇到空格直接跳过，如果不是空格，则计数器加1，然后用个while循环找到下一个空格的位置，这样就遍历完了一个单词，再重复上面的操作直至结束
*/

int countSegments(string s) 
{	
	int res=0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]==''||s[i]==',')
			continue;
		res++;
		while(i<s.size() && s[i]!='')
			++i;
	}
	return res;
}