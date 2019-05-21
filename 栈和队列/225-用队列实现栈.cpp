/*
* @author：sunny
* 225、用队列实现栈 
* https://leetcode-cn.com/problems/implement-stack-using-queues/
* 使用队列实现栈的下列操作：
*	- push(x) -- 元素 x 入栈
*	- pop() -- 移除栈顶元素
*	— top() -- 获取栈顶元素
*	- empty() -- 返回栈是否为空
*/	

/*
* 思路：这里用到两个队列，一个数据队列，一个临时队列。push操作要保证新元素在队列头部，那么先把新元素push到临时队列中（tempQ.push(x)），然后把数据队列的元素存入临时队列（dataQ-->tempQ），
*   这样新元素在临时队列的头部，然后再把临时队列的元素移到数据队列中即可（tempQ-->dataQ）。
*/

class MyStack
{
private:
	queue<int> data_queue;

public:	
	MyStack(){}
	
	void push(int x)
	{
		queue<int> tmp_queue;
		tmp_queue.push(x);//新元素放到临时队列中
		while(!data_queue.empty())//把所有元素移到临时队列中
		{
			tmp_queue.push(data_queue.front());
			data_queue.pop();
		}
		while(!tmp.empty())//把临时队列中元素移回去
		{
			data_queue.push(tmp_queue.front());
			tmp_queue.pop();
		}
	}
	
	int pop()
	{
		int x=data_queue.front();
		data_queue.pop();
		return x;
	}
	
	int top()
	{
		return data_queue.front();
	}
	
	bool empty()
	{
		return data_queue.empty();
	}
}

