/*
* @author：sunny
* 191、位1的个数
* https://leetcode-cn.com/problems/number-of-1-bits/
* 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数
*/	

/*
* 思路1：利用n&(n-1)将n最右侧的1置0。
*/

int hammingWeight(uint32_t n)
{
	int cnt=0;
	while(n)
	{
		n=n&(n-1);
		cnt++;
	}
	return cnt;
}

/*
* 思路2：将n逐位与1相与（取出该位），把取出的结果（不是0就是1）累加起来
*/

int hammingWeight(uint32_t n)
{	
	int cnt=0;
	for(int i=0;i<32;i++)
	{
		cnt+=(n&1);
		n=n>>1;		
	}
	return cnt;
}