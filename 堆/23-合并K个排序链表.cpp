/*
* @author：sunny
* 23、合并K个排序链表
* https://leetcode-cn.com/problems/merge-k-sorted-lists/
* 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
*/	

/*
* 思路：采用最小堆的数据结构，首先把k个链表的首元素都加入到最小堆中，它们会自动排好序，然后我们每次取出最小的那个元素加入我们最终结果的链表中，
*   然后把取出元素的下一个元素再加入堆中，下次仍从堆中取出最小的元素做相同的操作，以此类推，直到堆中没有元素了，
*   此时k个链表也合并为了一个链表，返回首节点即可。
* 
*/

struct cmp
{
	bool operator()(ListNode* &a,ListNode* &b)
	{
		return a->val > b->val;
	}
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	priority_queue<ListNode*,vector<ListNode*>,cmp> q;
	for(auto node:lists)
	{
		if(node!=NULL)
			q.push(node);
	}
	ListNode* dummy = new ListNode(0);
	ListNode* cur = dummy;
	while(!q.empty())
	{
		auto t = q.top();q.pop();
		cur->next = t;
		cur = cur->next;
		if(cur->next)
			q.push(cur->next);
	}
	return dummy->next;	
}