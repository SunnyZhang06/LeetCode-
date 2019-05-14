/*
* @author：sunny
* 21、合并两个有序链表
* https://leetcode-cn.com/problems/merge-two-sorted-lists/
* 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
*/

/*
* 方法：辅助头节点
* 思路：建立带头节点的新链表，指针cur不断指向链表的下一个节点（通过比较两个链表节点值的大小确定）
*   可以用递归和非递归两种方法来做。
*/

/*非递归*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if(l1==NULL)	return l2;
	if(l2==NULL)	return l1;	
	ListNode* newHead = new ListNode(0);
	ListNode* cur = newHead;
	
	while(l1 && l2)
	{
		if(l1->val <= l2->val)
		{
			cur->next = l1;
			l1=l1->next;
		}
		else
		{
			cur->next = l2;
			l2=l2->next;
		}
		cur=cur->next;
	}
	if(l1)
		cur->next = l1;//l1还没合并完
	if(l2)
		cur->next = l2;//l2还没合并完
	return newHead->next;
	
}

/*递归*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if(l1==NULL)	return l2;
	if(l2==NULL)	return l1;	
	ListNode* cur = NULL;
	
	if(l1->val <= l2->val)
	{
		cur=l1;
		cur->next=mergeTwoLists(l1->next,l2);
	}		
	else
	{
		cur=l2;
		cur->next=mergeTwoLists(l1,l2->next);
	}
	return cur;
}



