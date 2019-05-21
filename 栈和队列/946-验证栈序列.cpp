/*
* @author：sunny
* 946、验证栈序列
* https://leetcode-cn.com/problems/validate-stack-sequences/
* 给定 pushed 和 popped 两个序列，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。
*/	

/*
* 思路：使用栈和队列模拟入栈、出栈过程。将出栈结果存储在队列中，按顺序将元素push入栈，每push一个元素，检查是否与队列首部元素相同，相同则弹出队列首元素
*	和栈顶元素，直到两元素不同结束。若最终栈为空，说明序列合法。
*   
*/

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
	stack<int> S;
	queue<int> Q;	
	for(int i=0;i<popped.size();i++)
		Q.push(popped[i]);
	
	for(int i=0;i<popped.size();i++)
	{
		S.push(pushed[i]);
		while(!S.empty() && S.top()==Q.front())
		{
			S.pop();
			Q.pop();
		}
	}
	if(!S.empty())
		return false;
	return true;
	
}
