/*
* @author：sunny
* 876、链表的中间结点
* https://leetcode-cn.com/problems/middle-of-the-linked-list/
* 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
*/	

/*
* 方法：快慢指针
* 思路：这道题解法在143、234中都有出现过，就是利用快慢指针。
*/

ListNode* middleNode(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	
	while(fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow=slow->next;		
	}
	return slow->next;
	
	/*
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow=slow->next;	
	}
	return slow
	*/
}
