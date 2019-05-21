    
/*
* @author：sunny
* 20、有效的括号
* https://leetcode-cn.com/problems/valid-parentheses/
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
*/	

/*
* 思路：这里需要用一个栈，开始遍历输入字符串，如果当前字符为左半边括号(‘(’、‘[’、‘{’)时，则将其压入栈中，如果遇到右半边括号时，若此时栈为空，则直接返回false，
*   如不为空，则取出栈顶元素，若为对应的左半边括号，则继续循环，反之返回false。
*/

bool isValid(string s)
{
	if(s.empty())
		return true;
	stack<char> stk;
	for(int i=0;i<s.size();i++)
	{
		//左侧括号入栈，右侧括号进行判断
		if(s[i]='(' || s[i]='[' || s[i]='{')
			stk.push(s[i]);
		else
		{
			if(stk.empty())
				return false;
			if(s[i]==')' && stk.top()!='(')
				return false;
			if(s[i]==']' && stk.top()!='[')
				return false;
			if(s[i]=='}' && stk.top()!='{')
				return false;
			stk.pop();
		}		
	}
	return stk.empty();

}







