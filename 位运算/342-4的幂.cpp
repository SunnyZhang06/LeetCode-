/*
* @author：sunny
* 342、4的幂
* https://leetcode-cn.com/problems/power-of-four/
* 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
*/	

/*
* 思路1：和231中判断2的幂提到方法一样，不停除以4，看结果是否为1。
*/

bool isPowerOfFour(int num) 
{
	while(num && (num%4 ==0))
		num/=4;
	return num==1;
}

/*
* 思路2：4的次方数减1可以被3整除
*/

bool isPowerOfFour(int num) 
{
	return (num>0) && !(num&(num-1)) && (num-1)%3==0;
}