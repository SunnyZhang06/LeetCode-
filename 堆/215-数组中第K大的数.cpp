/*
* @author：sunny
* 215、数组中第K大的数
* https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
* 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/	

/*
* 思路1：最简单也是最容易想到的方法就是排序，然后通过下标(size-k)直接访问倒数第k个就可以。 
*/

int findKthLargest(vector<int>& nums, int k)
{	
	sort(nums.begin(),nums.end());//用stl中算法，复杂度 N*logN
	return nums[nums.size()-k];
}

/*
* 思路2：利用最小堆，先将前k个元素放入堆中，剩下的元素依次与堆顶元素比较，若比堆顶元素大，则先弹出堆顶然后将该元素入堆，
*   最终堆顶元素即为第K大数。
*/

int findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int,vector<int>,greater<int>> Q;//greater小顶堆
	
	for(int i=0;i<nums.size();++i)
	{
		if(Q.size()<k)
			Q.push(nums[i]);
		else if(nums[i] > Q.top())//新元素大则先弹出堆顶然后入堆
		{
			Q.pop();
			Q.push(nums[i]);
		}
	}
	return Q.top();	
	
	//堆的简便写法
	/*
	priority_queue<int> q(nums.begin(), nums.end());
	for (int i = 0; i < k - 1; ++i) {
		q.pop();
	}
	*/
}

/*
* 思路3：利用快排的分治思想直接找下标。
*/

int findKthLargest(vector<int>& nums, int k)
{
	int left=0,right=nums.size()-1;
	int index=partion(nums,left,right);
	while(index!=k-1)
	{
		if(index>k-1)
		{
			right=index-1;
			index=partion(nums,left,right);
		}
		else
		{
			left=index+1;
			index=partion(nums,left,right);
		}
	}
	return nums[index];
	
}

/*快排一次分治结果*/
int partion(vector<int> &nums,int low,int high)
{
    int pivot=nums[low];    
    while(low<high)
    {
        while(low<high && nums[high]<=pivot)
            high--;
        nums[low]=nums[high];                
        while(low<high && nums[low]>=pivot)
            low++;
        nums[high]=nums[low];        
    }
    nums[low]=pivot;
    return low;    
}