/*
* @author：sunny
* 67、 二进制求和
* https://leetcode-cn.com/problems/add-binary/
* 给定两个二进制字符串，返回他们的和（用二进制表示）
*/	

/*
* 思路：和链表专题中2两数相加有点类似，用两个指针分别指向a和b的末尾，然后每次取出一个字符，转为数字，若无法取出字符则按0处理，
*   然后定义进位carry，初始化为0，将三者加起来，对2取余即为当前位的数字，对2取商即为当前进位的值，
*   记得最后还要判断下carry，如果为1的话，要在结果最前面加上一个1，
*/

string addBinary(string a, string b) 
{
	string res = "";
	int carry = 0,m = a.size()-1, n = b.size()-1;
	while(m>=0||n>=0)
	{
		int p = m>=0?a[m--]-'0':0;
		int q = n>=0?b[n--]-'0':0;
		int sum = p + q + carry;
		res = to_string(sum % 2) + res;
		carry = sum / 2;
	}
	return carry == 1 ? "1" + res : res;         
}

/*
* 字符串与整数的互相转换可参考：https://www.jianshu.com/p/6fba2a542497
*/