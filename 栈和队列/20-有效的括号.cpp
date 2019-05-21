1//20有效的括号（括号匹配）

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







