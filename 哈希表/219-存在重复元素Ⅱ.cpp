/*
* @author：sunny
* 219、存在重复元素Ⅱ
* https://leetcode-cn.com/problems/contains-duplicate-ii/
* 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，
* 使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
*/

/*
* 方法1：用 map 建立数字到出现位置的映射 
* 思路：和217题类似，map统计每个数字出现的位置，{num：pos}，如果找到相同num，且位置差的绝对值不超过k，则返回
*       如果找到了但超过k，则要更新找到元素的最新位置，没找到时就依次记录出现的num和它的位置。
*/
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int,int> m;
	for(int i=0;i<nums.size();++i)
	{
		if(m.find(nums[i])!=nums.end() && i-m[nums[i]]<=k)//
			return true;
		else
			m[nums[i]]=i;
	}
	return false;
}
