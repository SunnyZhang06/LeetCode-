/*
* @author：sunny
* 461、汉明距离
* https://leetcode-cn.com/problems/hamming-distance/
* 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。给出两个整数 x 和 y，计算它们之间的汉明距离。
*/	

/*
* 思路1：取出每一位，然后异或(相同为1，不同为0)，根据异或结果来使计数变量加1.
*/

int hammingDistance(int x, int y)
{
	int cnt=0;
	for(int i=0;i<32;i++)
	{
		if((x&(1<<i)) ^ (y&(1<<i)))
			cnt++;		
	}
	return cnt;
}

/*
* 思路2：直接异或，然后统计1的个数。
*/

int hammingDistance(int x, int y)
{
	int cnt=0,ex=x^y;
	while(ex)
	{
		ex=ex&(ex-1);
		cnt++;
	}
	return cnt;
}