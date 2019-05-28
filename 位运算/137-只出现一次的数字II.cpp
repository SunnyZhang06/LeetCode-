/*
* @author：sunny
* 137、出现一次的数字II
* https://leetcode-cn.com/problems/single-number-ii/
* 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
*/	

/*
* 思路：可以建立一个32位的数字，来统计每一位上1出现的个数，如果某一位上为1的话，那么如果该整数出现了三次，对3去余为0，
*   然后把每个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字。
*/

int singleNumber(vector<int>& nums)
{
	int res=0;
	for(int i=0;i<32;i++)
	{
		int sum=0;
		for(int j=0;j<nums.size();j++)
			sum+=(nums[i]>>i)&1;//把每一位提取出来并求和
		
		res |= (sum%3)<<i;//如果不能整除3，说明该位的1是出现一次那个数造成的,通过或运算把每一位连起来
	}
	return res;
}

