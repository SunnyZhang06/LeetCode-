/*
* @author：sunny
* 260、只出现一次的数字III
* https://leetcode-cn.com/problems/single-number-iii/
* 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
*/	

/*
* 思路：与136(有一个元素出现一次，其他出现两次)、137(有一个元素出现一次，其他出现三次)不同，本题是有两个元素出现一次，其他出现两次。
*   考虑把这两个元素分在两个不同的小组，再用136中singleNumber1的方法。首先，全部元素异或，最终是那两个不同元素异或，如最后为：3^5（011^101=110）,
*   出现1说明该位不同，就可以区分这两个数了。然后，以某一位与数组相与，就可以把3和5分在两个不同的小组，然后再将两个小组中的数异或就可以。
*/

vector<int> singleNumber(vector<int>& nums)
{	
	int diff=0;
	for(int i=0;i<nums.size();i++)
		diff^=nums[i];
	diff &= -diff;//取出最右侧为1的位
	vector<int> res(2,0);
	
	for(auto &a:nums)
	{
		if(a&diff)//根据不同分成两个小组
			res[0]^=a;
		else
			res[1]^=a;
	}
	return res;
}
