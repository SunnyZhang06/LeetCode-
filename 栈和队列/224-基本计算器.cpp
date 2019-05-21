/*
* @author：sunny
* 224、基本计算器
* https://leetcode-cn.com/problems/basic-calculator/
* 实现一个基本的计算器来计算一个简单的字符串表达式的值。字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格 
*/	

/*
* 思路：使用栈和队列模拟入栈、出栈过程。将出栈结果存储在队列中，按顺序将元素push入栈，每push一个元素，检查是否与队列首部元素相同，相同则弹出队列首元素
*	和栈顶元素，直到两元素不同结束。若最终栈为空，说明序列合法。
*/

int calculate(string s)
{
	stack<int> st;
	
}

