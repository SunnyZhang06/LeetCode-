/*
* @author：sunny
* 141、环形链表
* https://leetcode-cn.com/problems/linked-list-cycle/
* 给定一个链表，判断链表中是否有环。
*/	

/*
* 方法：快慢指针
* 思路：快指针每次走两步，慢指针每次走一步，如果两者相遇，则一定有环，反之没有环（此时快指针先到头）
*/


bool hasCycle(ListNode *head)
{
	if(head==NULL || head->next==NULL)
		return false;
	
	ListNode* fast = head;//快指针
	ListNode* slow = head;//慢指针
	
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if(fast==slow)//快慢指针相遇
			return ture;
	}
	return false;
}











