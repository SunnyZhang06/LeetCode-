/*
* @author：sunny
* 143、重排链表
* https://leetcode-cn.com/problems/reorder-list/
* 原来：L0->L1->...->Ln；重排后：L0->Ln->L1->Ln-1->...
*/

/*
* 方法1：快慢指针
* 思路：将重排序问题可以拆分为以下三个小问题：
*   1. 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。
*   2. 将第二个链翻转。
*   3. 将第二个链表的元素间隔地插入第一个链表中。
*/

void reorderList(ListNode* head) 
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return;
	
	ListNode* fast = head;
	ListNode* slow = head;
	while(fast->next && fast->next->next)//上中位数
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//slow就是中点，从slow之后开始翻转
	ListNode* mid = slow->next;
	slow->next=NULL;
	ListNode* cur = mid,*pre=NULL;
	
	while(cur)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	
	//开始重构，pre为翻转后的头结点
	ListNode* first = head;
	ListNode* second = pre;
	while(first && second)//交叉插入
	{
		ListNode* curFirst = first;
		first = first->next;
		ListNode* curSecond = second;
		second = second->next;
		curFirst->next = curSecond;
		curSecond->next = first;
	}
	
}


/*
* 方法二：利用栈
* 思路：上面的第二步是将后半段链表翻转，那么其实可以借助栈的后进先出的特性来做，
*   如果我们按顺序将所有的结点压入栈，那么出栈的时候就可以倒序了，实际上就相当于翻转了链表。
*/

void reorderList(ListNode* head) 
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return;
	stack<ListNode*> st;
	ListNode* cur = head;
	while(cur)
	{
		st.push(cur);
		cur = cur->next;
	}
	int cnt = ((int)st.size()-1)/2;//链表的中间位置
	cur = head;
	while(cnt-- >0)
	{
		ListNode* top = st.top(); st.pop();
		ListNode* next = cur->next;
		cur->next = top;
		top->next = next;
		cur = next;
	}
	st.top()->next = NULL;
	
}


