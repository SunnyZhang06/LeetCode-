/*
* @author：sunny
* 190、颠倒二进制位
* https://leetcode-cn.com/problems/reverse-bits/
* 颠倒给定的 32 位无符号整数的二进制位。
*/	

/*
* 思路1：把要翻转的数从右向左一位位的取出来，如果取出来的是1，将结果res左移一位并且加上1；如果取出来的是0，将结果res左移一位，然后将n右移一位即可。
*/

uint32_t reverseBits(uint32_t n) 
{
	uint32_t res=0;
	for(int i=0;i<32;i++)
	{
		res<<=1;//每次左移一位（先移动把该位空出来再操作）
		if((n&1)==1)//n对应的位是1
			res++;
		n>>=1;//每次右移一位
		
		/*更简洁写法*/
		//res = (res<<1) + (n>>i)&1;
	}
	return res;
}

/*
* 思路2：先将n右移i位，然后通过与1来提取出该位，然后将其左移(31-i)位，就是翻转后应该在的位置，然后或上结果res（有1置1，全0置0）
*/

uint32_t reverseBits(uint32_t n) 
{
	uint32_t res=0;
	for(int i=0;i<32;i++)		
		res |= ((n>>i)&1) << (31-i);
	return res;
}