/*
* @author：sunny
* 268、缺失数字
* https://leetcode-cn.com/problems/missing-number/
* 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
*/	

/*
* 思路1：先根据等差数列求和公式求出0到n之间所有数字之和，然后减去遍历给定数组得到的和，差值就是丢失的数字
*/

int missingNumber(vector<int>& nums)
{
	int sum=0,n=nums.size();
	for(auto &a:nums)
		sum+=a;
	return 0.5*n*(n+1)-sum;
}

/*
* 思路2：利用136中的方法，将0~n完整的序列和给定0~n序列(缺数)异或(0可以不算，从1开始)。	
*/

int missingNumber(vector<int>& nums)
{
	int res=0;
	for(int i=0;i<nums.size();i++)
		res^=(i+1)^nums[i];
	return res;	
}

