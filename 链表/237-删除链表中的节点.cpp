/*
* @author：sunny
* 237、删除链表中的结点
* https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
* 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
*/

/*
* 方法：
* 思路：这里没有给出起始节点，之前要删除一个节点的方法是要有其前一个节点的位置，然后将其前一个节点的next连向要删节点的下一个
*   这道题的处理方法是先把当前节点的值用下一个节点的值覆盖了，然后删除下一个节点即可（覆盖掉节点）
*/

void deleteNode(ListNode* node)
{
	node->val = node->next->val;
	node->next = node->next->next;
}
