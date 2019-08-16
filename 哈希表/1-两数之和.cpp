/*
* @author：sunny
* 1、两数相加
* https://leetcode-cn.com/problems/two-sum/
* 给定一个整数数组 nums 和一个目标值 target，请你在该数组中
* 找出和为目标值的那 两个 整数，并返回他们的数组下标。
*/

/*
* 方法1：双循环暴力法时间复杂度为O(n^2)，这里利用HashMap，时间复杂度为O(n)
* 思路：使用一个 HashMap来建立数字和其坐标位置之间的映射，在遍历数组的时候，
* 用 target 减去遍历到的数字，就是另一个需要的数字了，直接在 HashMap 中查找其是否存在即可
*/

vector<int> twoSum(vector<int>& nums, int target) 
{
	unordered_map<int, int> m;
	vector<int> res;
	for(int i=0;i<nums.size();i++)
	{
		if(m.count(target-nums[i]))//或者把循环中的target-nums[i]和nums[i]互换
		{
			res.push_back(m[target-nums[i]]);
			res.push_back(i);
			break;
		}
		m[nums[i]] = i;
	}
	return res;
}

/*
* 方法2：双循环的方法
* 思路：这种方法复杂度比用HashMap复杂度高，主要是尝试用下 C++ <algorithm> 中的两个函数
*       find返回迭代器，distance返回俩个迭代器之间的距离
*/

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> res;
	for(int i=0;i<nums.size();++i)
	{
		auto it=find(nums.begin()+i+1,nums.end(),target-nums[i]);
		if(it!=nums.end())//找到
		{
			res.push_back(i);
			res.push_back(distance(nums.begin(),it));
			break;
		}
	}
	return res;
}
