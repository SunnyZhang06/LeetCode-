/*
* @author：sunny
* 155、最小栈
* https://leetcode-cn.com/problems/min-stack/
* 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
*	-push(x) -- 将元素 x 推入栈中。
*	-pop() -- 删除栈顶的元素。
*	-top() -- 获取栈顶元素。
*	-getMin() -- 检索栈中的最小元素。
*/	

/*
* 思路：这里需要用两个栈，一个栈用来保存push进来的数据，另一个栈保存出现过的最小值(实时保存最小值)。
*/

class MinStack
{
private:
	stack<int> data;
	stack<int> min;
	
public:
	Minstack(){}
	void push(int x)
	{
		data.push(x);//先将数据压入数据栈
		if(min.empty() || x<=min.top())
			min.push(x);//如果最小值栈为空或新元素比栈顶元素小，则新元素入栈
		else
			min.push(min.top());
		}
	}
	
	void  pop()
	{
		data.pop();
		min.pop();//同时出栈
	}
	
	int top()
	{
		return data.top();
	}
	
	int getMin()
	{
		return min.top();
	}
}

