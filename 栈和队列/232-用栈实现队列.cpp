/*
* @author：sunny
* 232、用栈实现队列 
* https://leetcode-cn.com/problems/implement-stack-using-queues/
* 使用栈实现队列的下列操作：
*	- push(x) -- 将一个元素放入队列的尾部。
*	- pop() --  从队列首部移除元素。
*	— top() -- 返回队列首部的元素。
*	- empty() -- 返回队列是否为空。
*/	

/*
* 思路：这里用到两个栈，一个数据栈，一个临时栈。push操作要保证新元素在栈尾，那么先把数据栈中元素移到临时栈中（dataS-->tempS），然后把新元素压入数据栈中（dataS.push(x)）
*   这样新元素在数据栈尾，然后再把临时栈的元素移到数据栈中即可（tempS-->dataS）。
*/

class MyQueue
{
private:
	stack<int> data_stk;
	
public:
	MyQueue(){}
	
	void push(int x)
	{
		stack<int> tmp_stk;		
		while(!data_stk.empty())//把所有元素移到临时栈中
		{
			tmp_stk.push(data_stk.top());
			data_stk.pop();
		}
		tmp_stk.push(x);//新元素放到临时栈中
		while(!tmp_stk.empty())//把临时栈中元素移回去
		{
			data_stk.push(tmp_stk.top());
			tmp_stk.pop();
		}
	}
	
	int pop()
	{
		int x=data_stk.top();
		data_stk.pop();
		return x;
	}
	
	int top()
	{
		return data_stk.top();
	}
	
	bool empty()
	{
		return data_stk.empty();
	}
}

