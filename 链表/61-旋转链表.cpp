/*
* @author：sunny
* 61、旋转链表
* https://leetcode-cn.com/problems/rotate-list/
* 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
*/

/*
* 方法：
* 思路：旋转k步就是要把倒数k个结点移到前面去，这里需要两次遍历，第一次遍历计算出链表的长度L和找出尾部节点
*   第二次遍历时进行旋转操作，可以在遍历到L-k个节点时把链表分成两段再拼起来，也可以先使链表成环再在适当位置断开
*/

/*方法一：分两段后拼接*/
ListNode* rotateRight(ListNode* head, int k)
{
	if(head==NULL || head->next==NULL || k<1)
		return head;
	ListNode* node=head;
	int L=1;
	while(node->next!=NULL)
	{
		node=node->next;// node 最后为尾部节点
		L++;//计算链表长度
	}
	int k=k%L;
	ListNode* tail=node;
	node=head;
	for(int i=1;i<L-k;++i)
		node=node->next;// node 最后为第 L-k 个节点
	tail->next=head;//首尾相连
	head=node->next;//新的头节点
	node->next=NULL;//新的尾节点
	return head;
}

/*方法二：先成环再断开*/
ListNode* rotateRight(ListNode* head, int k)
{
	if(head==NULL || head->next==NULL || k<1)
		return head;
	ListNode* node=head;
	int L=1;
	while(node->next!=NULL)
	{
		node=node->next;// node 最后为尾部节点
		L++;//计算链表长度
	}
	node->next=head;//使链表成环
	
	ListNode* p=head;
	int num=L-k%L;
	for(int i=1;i<num;++i)
		p=p->next;
	head=p->next;//此处断开，新的头节点
	p->next=NULL;//新的尾节点
	return head;
		
}

/*
* 注：求链表长度的两种写法
*/
int lengthOfList(ListNode* head)
{
	ListNode* p=head;
	int L=0;
	while(p!=NULL)
	{
		p=p->next;//p最后为NULL
		++L;
	}
	return L;
}
int lengthOfList(ListNode* head)
{
	ListNode* p=head;
	int L=1;
	while(p->next!=NULL)
	{
		p=p->next;//p最后为尾部节点
		++L;
	}
	return L;
}

