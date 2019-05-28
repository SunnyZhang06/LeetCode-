/*
* @author：sunny
* 371、两整数之和
* https://leetcode-cn.com/problems/sum-of-two-integers/
* 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
*/	

/*
* 思路：整数的加减运算可以用位运算来代替，二进制运算中1和1相加得到0，1和0相加得到1，这刚好符合异或的规律。
*   另外考虑到进位，只有两个1相加时才会进位，那么可以先与运算，然后左移一位实现进位的功能。
*/

int getSum(int a, int b)
{
	while (b) 
	{
		int carry = (a & b & 0x7fffffff) << 1;
		a = a ^ b;
		b = carry;
    }
    return a;
}

