/*
* @author：sunny
* 19、删除链表倒数第N个节点
* https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
* 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
*/

/*
* 方法：快慢指针
* 思路：设链表长度为L，让快指针先走 n 步，此时和链表尾部距离为 l-n，让后让快慢指针同时走 l-n 步，
*     此时慢指针的下一个即为倒数第 n 个节点，这里注意处理 n 刚好为链表长度的情况（即 n=l）。
*
* 快指针：
*	 A1->A2->...->An->An+1->...->Al
*	 |____________|    |_________|
*		   n                l-n	  
* 慢指针：		                   
*	A1->A2->...->A(l-n)->A(l-n+1)->...->Al
*	 |______________|      |_____________|
*		  l-n              |      n	
*	                  倒数第 n 个
*/	 
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if(head==NULL || n<0)
		return NULL;
	ListNode* fast=head;
	ListNode* slow=head;	
	
	for(int i=0;i<n;i++)//快指针先走 n 步
		fast=fast->next;
	if(fast==NULL)//n刚好为链表长度，倒数第 n 个即为第一个节点（头节点）
		return head->next;
	while(fast->next)
	{
		fast = fast->next;//快慢指针一起走到最后
		slow = slow->next;
	}
	slow->next=slow->next->next;
	return head;
}


/*
* 注：上述清况是为了方便删除让快指针先走了 n 步，如果是单纯访问倒数第 n 个节点，快指针走 n-1 步即可，代码如下
*/

ListNode* findNthtoTail(ListNode* head,int n)
{
	if(head==NULL || n<1)
		return NULL;
	ListNode* fast=head;
	ListNode* slow=head;
	for(int i=0;i<n-1;i++)
	{
		fast=fast->next;
		if(fast==NULL)
			return NULL;//当链表长度小于 n ，直接返回NULL
	}
	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

