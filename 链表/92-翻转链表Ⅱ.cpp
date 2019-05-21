/*
* @author：sunny
* 92、翻转链表Ⅱ（翻转从位置m到n的链表）
* https://leetcode-cn.com/problems/reverse-linked-list-ii/
* 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
*/

/*
* 方法1：辅助头节点
* 思路：为防止出现从节点1开始变换的情况，这里新建辅助头节点（dummy节点），要求一次遍历完成，在遍历过程中把m到n这段截取出来进行翻转即可
*/

ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	ListNode* node = newHead;
	
	for(int i=0;i < m-1;i++)
		node = node->next;//node最后为第m-1个结点		
	head = node->next;//此时head为第m个结点
	
	ListNode* tail = head;	
	for(int i=m;i<n;i++)
		tail = tail->next;//tail最后为第n个节点
	ListNode* pre = tail->next;//第n+1个节点
	tail->next=NULL;	
	
	ListNode* cur=head;
	ListNode* next=NULL;
	while(cur)
	{ 
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur=next;		
	}
	node->next = pre;
	return newHead->next;
}

/*
* 方法2：辅助头节点
* 思路：基本思路和上面一致，这里对m到n这段链表采用头插法原地翻转，写出来更简洁
*/
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	ListNode *dummy = new ListNode(0), *pre = dummy;
	dummy->next = head;
	for (int i = 0; i < m - 1; ++i) pre = pre->next;
	ListNode *cur = pre->next;
	for (int i = m; i < n; ++i) //头插法翻转链表
	{
		ListNode *t = cur->next;
		cur->next = t->next;
		t->next = pre->next;
		pre->next = t;
	}
	return dummy->next;
}

	

