/*
* @author：sunny
* 151、翻转字符串里的单词
* https://leetcode-cn.com/problems/reverse-words-in-a-string/
* 给定一个字符串，逐个翻转字符串中的每个单词。
*/	

/*
* 思路1：先整个字符串整体翻转一次，然后再分别翻转每一个单词。用storeIndex表示当前存储到的位置，翻转后进行遍历。
*   遇到空格直接跳过，如果是非空格字符，此时看storeIndex是否为0，为0的话表示第一个单词，不用增加空格；如果不为0，说明不是第一个单词，
*   需要在单词中间加一个空格，然后要找到下一个单词的结束位置。用一个while循环来找下一个为空格的位置，在此过程中继续覆盖原字符串，
*   找到结束位置了，下面就来翻转这个单词，然后更新i为结尾位置，最后遍历结束，我们剪裁原字符串到storeIndex位置，就可以得到需要的结果。
*/

string reverseWords(string s) 
{
    int storeIndex = 0, n = s.size();
	reverse(s.begin(),s.end());
	for(int i=0;i<n;++i)
	{
		if(s[i]!='')
		{
			if(storeIndex!=0)
				s[storeIndex++] = ' ';
			int j=i;
			while(j<n && s[j]!=' ')
				s[storeIndex++] = s[j++];
			reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
			i = j;
		}
	}
	s.resize(storeIndex);
}

/*
* 思路2：用字符串流类stringstream的解法。先把第一个单词赋给s，然后把取出的单词用“头插法”不断加入到s中。
*   注意：如果原字符串为空，那么就不会进入while循环；如果原字符串为许多空格字符连在一起，那么第一个>>操作就会提取出这些空格字符放入s中，
*   然后不进入while循环，这时候只要判断一下s的首字符是否为空格字符，是的话就将s清空即可。
*/

string reverseWords(string s) 
{
	istringstream is(s);
	string tmp;
	is >> s;//把第一个单词赋给s
	while(is>>tmp);
		s += tmp + " " + s;
	if(!s.empty() && s[0]==' ')
		s = " ";
	return s;
}

/*
* 思路3：同样使用stringstream，但是用了getline函数来做，第三个参数是设定分隔字符，这里用空格字符来分隔，这个跟上面的>>操作是有不同的，
*   每次只能过一个空格字符，如果有多个空格字符连在一起，那么t会赋值为空字符串，所以我们在处理t的时候首先要判断其是否为空，是的话直接跳过
*/

void reverseWords(string &s) 
{
	istringstream is(s);
	s = "";
	string t = "";
	while (getline(is, t, ' ')) 
	{
		if (t.empty()) 
			continue;
		s = (s.empty() ? t : (t + " " + s));
	}
	return s;
}
