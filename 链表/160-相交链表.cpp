/*
* @author：sunny
* 160、相交链表
* https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
* 编写一个程序，找到两个单链表相交的起始节点。
*/

/*
* 方法1：双指针
* 思路：分别计算出两个链表的长度L1和L2，然后让指向较长链表的指针先走（L1-L2）步，然后让两指针再同时走，相遇的地方就是相交的起始节点
*/


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if(headA==NULL || headB==NULL)
		return NULL;
	ListNode* p1 = headA;
	ListNode* p2 = headB;
	
	int La = GetLength(headA);
	int Lb = GetLength(headB);
	
	int L = La-Lb;
	if(L>=0)//A长，先走L步
	{
		for(int i=0;i<L;i++)
			p1 = p1->next;
	}
	else//B长，先走L步
	{
		for(int i=0;i<L;i++)
			p2 = p2->next;
	}
	
	while(p1 && p2 && p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
}
int GetLength(ListNode* head)
{
	int cnt = 0;
	while(head)
	{
		head=head->next;
		cnt++;
	}
	return cnt;
}


/*
* 方法1：链表成环思想
* 思路：虽然题目中强调了链表中不存在环，但是可以用环的思想来做，让两条链表分别从各自的开头开始往后遍历，
*   当其中一条遍历到末尾时，跳到另一个条链表的开头继续遍历。两个指针最终会相等，而且只有两种情况，一种情况是在交点处相遇，
*   另一种情况是在各自的末尾的空节点处相等。为什么一定会相等呢，因为两个指针走过的路程相同，是两个链表的长度之和，所以一定会相等。
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if(!headA || !headB)
		return NULL;
	ListNode* p1 = headA;
	ListNode* p2 = headB;
	
	while(p1!=p2)
	{
		p1 = p1?p1->next:p2;
		p2 = p2?p2->next:p1;
	}
	return p1;
}


