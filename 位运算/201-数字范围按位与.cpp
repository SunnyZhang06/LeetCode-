/*
* @author：sunny
* 201、数字范围按位与
* https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
* 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
*/	

/*
* 思路1：利用n&(n-1)每次去掉最低位的1，如果小于等于m，返回此时的n。如5(0101),6(0110),7(0111),三个数字按位与结果4（0100）
*/

int rangeBitwiseAnd(int m, int n)
{
	while(m<n)
		n=n&(n-1);
	return n;
}

/*
* 思路2：向右平移m和n直到相等并统计平移次数cnt，相等时把m再向左平移cnt位。如m=5(0101),n=7(0111),相等时：m=n=0001,cnt=2，m再向左平移2位：0100
*/

int rangeBitwiseAnd(int m, int n)
{
	int i=0;
	while(m!=n)
	{
		m>>=1;
		n>>=1;
		i++;
	}
	return (m<<i);
}