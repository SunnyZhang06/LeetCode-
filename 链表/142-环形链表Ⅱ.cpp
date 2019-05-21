/*
* @author：sunny
* 142、环形链表Ⅱ
* https://leetcode-cn.com/problems/linked-list-cycle-ii/
* 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
*/	

/*
* 方法：快慢指针
* 思路：和141题不一样的是本题要求返回链表入口节点，同样采用快慢指针法，两个指针相遇后，让慢指针从头开始，两个指针再走相同步数相遇的地方即为入口点。
*/

ListNode *detectCycle(ListNode *head)
{
	if(	if(head==NULL || head->next==NULL)
		return NULL;
	
	ListNode* fast = head;
	ListNode* slow = head;
	
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if(fast == slow)//相遇
		{
			slow = head;
			while(slow!=fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return fast;
		}
	}
	return NULL;
}
