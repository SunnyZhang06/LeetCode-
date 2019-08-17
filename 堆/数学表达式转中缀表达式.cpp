//数学运算表达式转中缀表达式

stack<char> str;
queue<char> res;
map<char,int> p;//设置优先级

void change(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')//左括号入栈
		{
			str.push(s[i]);		
			i++;
		}
		else if(s[i]==')')//右括号出栈
		{
			while(!str.empty() && s.top()!='(')
			{
				res.push(str.top());
				str.pop();
			}
			s.pop();//弹出左括号
			i++;
		}
		else if(s[i]>='0' && s[i]<='9')//如果是数字
		{
            int num=0;
            while(i<str.size() && str[i] >= '0'&&str[i] <= '9')
            {
                num=10*num+str[i++]-'0';
            }
            char tmp;
            itoa(num,&tmp,10);
            q.push(tmp);//操作数进入后缀表达式						
		}
		
		else//如果是操作符，判断优先级 
		{
			while(!s.empty() && p[s.top()]>=p[s[i]])
			{
				q.push(s.top());
				s.pop();
			}
			s.push(str[i]);
            i++;
		}
			
	}
	
	while(!s.empty())//将栈中剩余内容依次弹出后缀表达式
	{
		q.push(s.top() );
		s.pop();
	}
}

int main()
{
    string str;
	p['+'] = p['-'] = 1;//通过hashmap赋值
	p['*'] = p['/'] = 2;
	cin >> str;
	change(str);
	while (!q.empty())//遍历队列
	{
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}






