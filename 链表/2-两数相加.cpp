/*
* @author：sunny
* 2、两数相加
* https://leetcode-cn.com/problems/add-two-numbers/
* 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
* 并且它们的每个节点只能存储 一位 数字。
*/


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	int carry = 0;
	
	while(l1 || l2)
	{
		int val1 = l1?l1->val:0;
		int val2 = l2?l2->val:0;
		int sum = val1 + val2 + carry;
		carry = sum/10;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		
		l1 = l1?l1->next:l1;
		l2 = l2?l2->next:l2;
	}
	if(carry)
		cur->next = new ListNode(1);
	return head->next;
}






