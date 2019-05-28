
4//191位1的个数

int hammingWeight(uint32_t n)
{
	//利用n&(n-1)将n最右侧的1置0
	int cnt=0;
	while(n)
	{
		n=n&(n-1);
		cnt++;
	}
	return cnt;
	
	//将n逐位与1相与（取出该位），把取出的结果（不是0就是1）累加起来
	
	int cnt=0;
	for(int i=0;i<32;i++)
	{
		cnt+=(n&1);
		n=n>>1;		
	}
	return cnt;
}

