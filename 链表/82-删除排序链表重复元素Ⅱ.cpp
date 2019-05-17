/*
* @author：sunny
* 82、删除排序链表重复元素(相同的元素一个不保留)
* https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
* 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
*/

/*
* 方法1：双重指针
* 思路：和83题不同的是本题要求相同的元素一个不保留，这里用一个指针遍历链表节点，另一个指针保存不含重复元素的链表节点的指针（指向指针的指针）
*/

ListNode* deleteDuplicates(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return head;
	
	ListNode* cur = head;
	ListNode** curNext = &head;
	
	while(cur!=NULL)
	{
		ListNode* tmp = cur;
		while(cur->next && cur->val==cur->next->val)
			cur=cur->next;
		
		if(cur==tmp)//前后结点值不相等，且不是重复元素结点
		{
			*curNext=tmp;//把不重复结点的指针保存起来
			curNext=&(*curNext)->next;
		}
		cur=cur->next;
	}
	*curNext = NULL;
	return head;
	
}

/*
* 方法2：辅助头节点
* 思路：由于链表开头可能会有重复项，被删掉的话头指针会改变，而最终却还需要返回链表的头指针。所以需要定义一个新的节点，
*   然后链上原链表，然后定义一个前驱指针和一个现指针，每当前驱指针指向新建的节点，现指针从下一个位置开始往下遍历，
*   遇到相同的则继续往下，直到遇到不同项时，把前驱指针的next指向下面那个不同的元素。如果现指针遍历的第一个元素就不相同，
*   则把前驱指针向下移一位和83题不同的是本题要求相同的元素一个不保留。
*
*	dummy————>1————>2————>2—————>3————>4————>。。。
*	  |       |     |     |
*	 pre     head   |     |
*		  |     |     |
*                pre   cur  cur->next
*/
ListNode* deleteDuplicates(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return head;
	ListNode* dunmmy=new ListNode(0);
	ListNode* pre=dummy;
	dummy->next=head;
	
	while(pre->next)
	{
		ListNode* cur=pre->next;
		while(cur->next && cur->val==cur->next->val)
			cur=cur->next;// cur 最后指向重复元素中最后一个的节点，如图中例子，循环结束后cur指向最后一个节点2
		if(cur!=pre->next)//不等说明 cur 已经后移，遇到重复元素
			pre->next=cur->next;
		else
			pre=pre->next;
	}
	return dummy->next;
}






















