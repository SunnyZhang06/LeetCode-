/*
* @author：sunny
* 206、翻转链表
* https://leetcode-cn.com/problems/reverse-linked-list/
* 反转一个单链表
*/

/*
* 方法1：原地翻转
* 思路：将每个节点不断指向前一个节点，实现原地翻转
*/

ListNode* reverseList(ListNode* head) 
{
	if(head==NULL)
		return head;	
	ListNode* cur=head;//指向当前节点
	ListNode* pre=NULL;//指向前一个节点
	ListNode* next=NULL;//指向后一个节点	
	while(cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

/*
* 方法2：头插法
* 思路：在原链表之前建立一个空的newHead，因为首节点会变，然后从head开始，将之后的一个节点移到newHead之后，重复此操作直到head成为末节点为止
*/

/*不使用辅助头节点*/
ListNode* reverseList(ListNode* head) 
{
	ListNode* newHead = NULL;
	while(head)
	{
		ListNode* temp = head->next;
		head->next = newHead;
		newHead = head;
		head=temp;
	}
	return newHead;	
}

/*使用辅助头节点*/
ListNode* reverseList(ListNode* head) 
{
	ListNode* dummy = new ListNode(0);
	dummy->next = NULL;
	
	while(head)
	{
		ListNode* temp = head->next;
		head->next = dummy->next;
		dummy->next = head;
		head = temp;
	}
	return dummy->next;	
}

/*
* 方法3：递归法
* 思路：不断的进入递归函数，直到head指向倒数第二个节点
*/

ListNode* reverseList(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return head;
	ListNode* newHead = reverseList(head->next);
	head->next->next = head;
	head->next=NULL;
	return newHead;
}

