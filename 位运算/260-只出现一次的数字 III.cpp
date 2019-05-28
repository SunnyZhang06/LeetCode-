

7//260只出现一次的数字 III（有两个元素出现一次，其他出现两次）

vector<int> singleNumber(vector<int>& nums)
{
	//分成两个小组，在用singleNumber1的方法
    //1、先全部亦或，得到3^5（011^101=110）,出现1说明该位不同，就可以区分这两个数了
    //2、然后以某位和数组相与，就可以把3和5分在两个不同的小组，然后再将两个小组中的数亦或就可以
	
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
