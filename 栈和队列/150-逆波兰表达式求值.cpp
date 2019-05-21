

2//150逆波兰表达式求值

int perop(int a,int b, string op)
{
	if(op="+")
		return a+b;
	else if(op=="-")
        return a-b;
    else if(op=="*")
        return a*b;//乘除法注意顺序
    else if(op=="/")
        return a/b;
	return 0；
}

int evalRPN(vector<string>& tokens)
{
	//遇到数字存起来，遇到符号取出两个数并运算，将结果存到栈中
	stack<int> ss;
	for(auto str:tokens)
	{
		if(str=="+"||str=="-"||str=="*"||str=="/")
		{
			int a=ss.top();ss.pop();
			int b=ss.top();ss.pop();
			int c=perop(b,a,str);
			ss.push(c);
		}
		else
			ss.push(atoi(str.c_str()));
	}
	return ss.top();
}


