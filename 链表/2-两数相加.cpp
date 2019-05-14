//2、两数相加：https://leetcode-cn.com/problems/add-two-numbers/
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

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







