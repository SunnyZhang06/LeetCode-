/*
* @author：sunny
* 24. 两两交换链表中的节点
* https://leetcode-cn.com/problems/swap-nodes-in-pairs/
* 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表
*/

/*
* 方法：辅助头节点
* 思路：建立带头节点的新链表，指针cur不断指向链表的下一个节点 
*
* 交换前：   cur	 node1	 node2	 rear
*	  dummy——————>1——————>2——————>3————>4————>。。。
* 交换一次后：
*					|———————————————>|
*			      dummy	1<——————2	 3————>4————>。。。
*				|_______________|
*
* 然后把 cur 更新为 node1，重复这个过程就可以了。
*         cur	  node1	  node2	   rear
*        dummy——————>2——————>1——————>3————>4————>。。。
* 
*/
ListNode* swapPairs(ListNode* head) 
{
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *cur = dummy;
	
	while(cur->next && cur->next->next)
	{
		ListNode* node1 = cur->next;
		ListNode* node2 = node1->next;
		ListNode* rear = node2->left;
		cur->next = node2;
		node2->next = node1;
		node1->cur = rear;
		cur = node1;//一次走一步	
	}
	return dummy->next;	
}

