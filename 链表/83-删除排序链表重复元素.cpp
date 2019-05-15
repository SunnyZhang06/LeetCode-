/*
* @author：sunny
* 83、删除排序链表重复元素(相同的元素保留一个)
* https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
* 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
*/

/*
* 方法：双指针
* 思路：这题要求相同的元素保留一个，这里用两个相邻指针遍历链表的过程中判断它们值是否相等，如果相等则删除后面的节点，继续往下遍历
*/

ListNode* deleteDuplicates(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return head;	
	ListNode* p = head;
	ListNode* q = p->next;
	
	while(q)
	{
		if(p->val==q->val)//如果值相等，则删除相应节点
		{
			p->next = q->next;
			q = p->next;
		}
		else//不想等则继续往下遍历
		{
			p=q;
			q=q->next;
		}
	}	
	return head;
}

