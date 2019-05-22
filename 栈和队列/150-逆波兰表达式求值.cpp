/*
* @author：sunny
* 150、逆波兰表达式求值
* https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
* 根据逆波兰表示法，求表达式的值。有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
*/	

/*
* 思路：这里需要用一个栈，遍历输入字符串的过程中，遇到数字存入栈中，遇到符号取出两个数并运算，将结果存到栈中。
*/

int evalRPN(vector<string>& tokens)
{	
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
			ss.push(atoi(str.c_str()));//字符串转化成数字存入栈中
	}
	return ss.top();
}

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


