/*
* @author：sunny
* 203、移除链表元素
* https://leetcode-cn.com/problems/remove-linked-list-elements/
* 删除链表中等于给定值 val 的所有节点。
*/

/*
* 方法1：辅助头节点
* 思路：为了防止出现删除头节点的情况，建立辅助头节点dummy。temp代表要比较的节点，pre表示要比较的节点的前一个节点。从dummy开始，边遍历边比较。
*/

ListNode* removeElements(ListNode* head, int val) 
{
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* pre = dummy;
	ListNode* temp = NULL;	
	while(pre->next)
	{
		temp = pre->next;
		if(temp->val == val)
			pre->next=temp->next;
		else
			pre = pre->next;
	}
	return dummy->next;
	
}

/*
* 方法1：双重指针
* 思路：用双重指针保存指向链表节点的指针，如果节点的值和要删除的值相等，就跳过这个指针，反之就把这个指针保存起来。
*/

ListNode* removeElements(ListNode* head, int val) 
{	
	ListNode** cur = &head;
	while(*cur)
	{
		ListNode* tmp = *cur;
		if(tmp->val == val)
		{
			*cur = (*cur)->next;
			delete tmp;
		}
		else
			cur = &((*cur)->next);
	}	
	return head;	
}





