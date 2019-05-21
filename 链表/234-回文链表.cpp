/*
* @author：sunny
* 234、回文链表
* https://leetcode-cn.com/problems/palindrome-linked-list/
* 请判断一个链表是否为回文链表。要求 O(n) 时间复杂度和 O(1) 空间复杂度
*/

/*
* 方法：快慢指针、翻转链表
* 思路：采用快慢指针法找链表中点，然后将后半段翻转，把前半段和翻转后的后半段逐个节点比较即可。
*/

bool isPalindrome(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return true;
	
	ListNode* fast = head;
	ListNode* slow = head;	
	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	
	ListNode* cur=slow->next;//后半段的头结点
	slow->next=NULL;
	ListNode* pre=NULL;
	ListNode* next=NULL;
	
	while(cur)//翻转后半段
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	
	pre=cur;//后半段翻转后头
	fast=head;//前半段头
	while(cur)
	{
		if(cur->val != fast->val)
			return false;
		cur=cur->next;
		fast=fast->next;
	}
	return true;
}


