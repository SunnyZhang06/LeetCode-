/*
* @author：sunny
* 703、数据流中的第K大元素
* https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
* 设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
*/	

/*
* 思路：建立一个小根堆来保存前K个数字，当再加入新数字后，最小堆会自动排序，然后把排序后的最小的那个数字去除，
*   则堆中还是K个数字，返回的时候只需返回堆顶元素即可。		  
*/

class KthLargest
{
private:
	priority_queue<int, vector<int>, greater<int>> q;
	int K;
public:
	KthLargest(int k, vector<int>& nums) 
	{
		for(auto num:nums)
		{
			q.push(num);
			if(q.size()>k)
				q.pop();
		}
		K = k;
	}
	
	int add(int val) 
	{
		q.push(val);
		if(q.size() > K)
			q.pop();
		return q.top();
	}	
}


    



