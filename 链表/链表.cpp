//常用方法：辅助头节点、快慢指针、双重指针

1//2两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	int carry = 0;
	
	while(l1 || l2)
	{
		int val1 = l1?l1->val:0;
		int val2 = l2?l2->val:0;
		int sum = val1 + val2 + carry;
		carry = sum/10;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		
		l1 = l1?l1->next:l1;
		l2 = l2?l2->next:l2;
	}
	if(carry)
		cur->next = new ListNode(1);
	return head->next;
}

2//19删除链表倒数第N个节点
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if(head==NULL || n<0)
		return NULL;
	ListNode* fast=head;
	ListNode* slow=head;
	ListNode* pre=NULL
	
	for(int i=0;i<n-1;i++)//快指针先走n-1步
	{
		fast=fast->next;
		if(fast==NULL)
			return NULL;//n大于链表长度
	}
	while(fast->next)
	{
		pre = fast;
		fast = fast->next;//快慢指针一起走到最后
		slow = slow->next;
	}
	
	if(pre==NULL)//N为链表长度，倒数第N个刚好是第一个结点
	{
		head=slow->next;
		delete slow;		
	}
	else
	{
		pre->next=fast->next;
		delete fast;
	}
	return head;
}


3//21合并两个有序链表
/*非递归*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if(l1==NULL)	return l2;
	if(l2==NULL)	return l1;
	
	ListNode* newHead = new ListNode(0);
	ListNode* cur = newHead;
	
	while(l1 && l2)
	{
		if(l1->val <= l2->val)
		{
			cur->next = l1;
			l1=l1->next;
		}
		else
		{
			cur->next = l2;
			l2=l2->next;
		}
		cur=cur->next;
	}
	if(l1)
		cur->next = l1;//l1还没合并完
	if(l2)
		cur->next = l2;//l1还没合并完
	return newHead->next;
	
}

/*递归*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if(l1==NULL)	return l2;
	if(l2==NULL)	return l1;
	
	ListNode* cur = NULL;
	
	if(l1->val <= l2->val)
	{
		cur=l1;
		cur->next=mergeTwoLists(l1->next,l2);
	}		
	else
	{
		cur=l2;
		cur->next=mergeTwoLists(l1,l2->next);
	}
	return cur;
}

4//24两两交换节点

交换前： cur	 node1	 node2	 rear
		dummy——————>1——————>2——————>3————>4
交换后：
					|———————————————|
		dummy		1<——————2		3————>4
			|_______________|
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

5//61旋转链表

//旋转k步就是要把倒数k个结点移到前面去
ListNode* rotateRight(ListNode* head, int k)
{
	if(head==NULL || head->next==NULL || k<0)
		return head;
		
	ListNode* node = head;
	ListNode* tail = head;
	int length = 0;
	
	while(node!=NULL)
	{
		tail = node;//保存链表尾部结点
		node = node->next;
		length++; //计算链表长度
	}
	
	k = k%length;
	node = head;
	
	for(int i=1;i<length-k;i++)
	{
		node = node->next;
	}
	tail->next = head;
	head = node->next;
	node->next = NULL;
	return head;
	
	
}


6//83删除排序链表重复元素(相同的元素保留一个)

ListNode* deleteDuplicates(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return head;
	
	ListNode* p = head;
	ListNode* c = p->next;
	
	while(c)
	{
		if(p->val==c->val)
		{
			p->next = c->next;
			delete c;
			c = p->next;
		}
		else
		{
			p=c;
			c=c->next;
		}
	}
	
	return head;
}


7//82删除排序链表重复元素(相同的元素一个不保留)

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
8//92翻转链表Ⅱ（翻转从位置m到n的链表）

ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	ListNode* node = newHead;
	
	for(int i=0;i<m-1;i++)//第m个结点的前一个
		node = node->next;
		
	head = node->next;//此时head为第m个结点
	
	ListNode* tail = head;
	
	for(int i=0;i<n-m;;i++)//从第m个到第n个
		tail = tail->next;
	ListNode* pre = tail->next;//第n个的后一个结点
	tail->next=NULL;
	
	
	ListNode* cur=head;*next;
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
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	ListNode *dummy = new ListNode(-1), *pre = dummy;
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

ListNode* reverseBetween(ListNode* head, int m, int n) {
        
	if(head==NULL || head->next==NULL || m>=n)
		return head;
	
	ListNode *p=head;
	ListNode *q=NULL;	
	for(int i=0;i<m-1;i++)
	{
		q=p;//第m个的前一个结点
		p=p->next;//第m个结点
	}
	
	ListNode *cur=p;
	ListNode *pre=NULL;
	ListNode *ne=NULL;
	for(int i=1;i<=n-m+1;i++)//对m到n这段进行翻转
	{
		ne=cur->next;
		cur->next=pre;
		pre=cur;
		cur=ne;
	}
	
	//return cur;
			
	q->next=pre;
	p->next=cur;
	
	return head;       
       
    }
	

9//141环形链表

bool hasCycle(ListNode *head)
{
	if(head==NULL || head->next==NULL)
		return false;
	
	ListNode* fast = head;//快指针
	ListNode* slow = head;//慢指针
	
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if(fast==slow)//快慢指针相遇
			return ture;
	}
	return false;
}


10//142环形链表Ⅱ（返回环的入口）

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


11//143重排链表（原来：L0->L1->...->Ln；重排后：L0->Ln->L1->Ln-1->...）

void reorderList(ListNode* head) 
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return;
	
	ListNode* fast = head;
	ListNode* slow = head;
	while(fast->next && fast->next->next)//上中位数
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//slow就是中点，从slow之后开始翻转
	ListNode* mid = slow->next;
	slow->next=NULL;
	ListNode* cur = mid,*pre=NULL;
	
	while(cur)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	
	//开始重构，pre为翻转后的头结点
	ListNode* first = head;
	ListNode* second = pre;
	while(first && second)//交叉插入
	{
		ListNode* curFirst = first;
		first = first->next;
		ListNode* curSecond = second;
		second = second->next;
		curFirst->next = curSecond;
		curSecond->next = first;
	}
	
}

//利用栈
void reorderList(ListNode* head) 
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return;
	stack<ListNode*> st;
	ListNode* cur = head;
	while(cur)
	{
		st.push(cur);
		cur = cur->next;
	}
	int cnt = ((int)st.size()-1)/2;//链表的中间位置
	cur = head;
	while(cnt-- >0)
	{
		ListNode* top = st.top(); st.pop();
		ListNode* next = cur->next;
		cur->next = top;
		top->next = next;
		cur = next;
	}
	st.top()->next = NULL;
	
}


12//160相交链表
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode* p1 = headA;
	ListNode* p2 = headB;
	
	while(p1!=p2)
	{
		p1 = p1?p1->next:p2;
		p2 = p2?p2->next:p1;
	}
	return p1;
}

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
	if(head==NULL)
		return 0;
	int cnt = 0;
	ListNode* p=head;
	while(p)
	{
		p=p->next;
		cnt++;
	}
	return cnt;
}

13//203移除链表元素(删除链表中等于给定值 val 的所有节点)

//双重指针
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

//辅助头结点
ListNode* removeElements(ListNode* head, int val) 
{
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* pre = dummy;
	
	while(pre->next)
	{
		if(pre->next->val == val)
		{
			ListNode* t = pre->next;
			pre->next = t->next;
			t->next = NULL;
			delete t;
		}
		else
			pre = pre->next;
	}
	return dummy->next;
	
}

14//206翻转链表

ListNode* reverseList(ListNode* head) 
{
	if(head==NULL)
		return head;
	
	ListNode* cur=head;
	ListNode* pre=NULL;
	ListNode* next=NULL;	
	while(cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

//递归法
ListNode* reverseList(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return head;
	ListNode* newHead = reverseList(head->next);
	head->next->next = head;
	head->next=NULL;
	return newHead;
}

15//234回文链表

bool isPalindrome(ListNode* head)
{
	if(head==NULL || head->next==NULL)
		return true;
	
	ListNode* fast = head;
	ListNode* slow = head;
	
	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	
	ListNode* cur=slow->next;//后半段的头结点
	slow->next=NULL;
	ListNode* pre=NULL;
	ListNode* next=NULL;
	
	while(cur)
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	
	pre=cur;
	fast=head;
	while(cur)
	{
		if(cur->val != fast->val)
			return false;
		cur=cur->next;
		fast=fast->next;
	}
	return true;
}


16//237删除链表中的结点

void deleteNode(ListNode* node)//覆盖掉结点
{
	node->val = node->next->val;
	node->next = node->next->next;
}

17//876链表的中间结点

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

















