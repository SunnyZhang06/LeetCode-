/*
* @author：sunny
* 231、2的幂
* https://leetcode-cn.com/problems/power-of-two/
* 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/	

/*
* 思路1：2的次方数二进制形式：1后面跟一串0，将n逐位与1相与（取出该位），把取出的结果（不是0就是1）累加起来，结果为1则是2的幂，否则不是。
*/

bool isPowerOfTwo(int n)
{	
	int cnt=0;
	while(n>0)
	{
		cnt+=(n&1);
		n=n>>1;
	}
	return cnt==1;	
}

/*
* 思路2：利用n&(n-1)去掉n最右的1，如 8&7=0。
*/

bool isPowerOfTwo(int n)
{	
	return (n>0) && (!(n&(n-1)));
}

/*
* 思路3：不停除以2,看结果是否为1
*/

bool isPowerOfTwo(int n)
{		
	while(n && (n%2 ==0))
		n/=2;
	return n==1;	
}