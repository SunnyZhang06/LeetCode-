/*
* @author：sunny
* 8、字符串转换整数 (atoi)
* https://leetcode-cn.com/problems/string-to-integer-atoi/
* 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
*/	

/*
* 思路：根据题意考虑一下几种情况：1、若字符串开头是空格，则跳过所有空格，到第一个非空格字符；
*   2、若第一个非空格字符是符号 +/-，则标记 sign 的真假；3、若下一个字符不是数字，则返回0. 完全不考虑小数点和自然数的情况；
*   4、如果下一个字符是数字，则转为整形存下来；5、如果超过了整型数的范围，则用边界值替代当前值。
*/

int myAtoi(string str) 
{
	if(str.empty())
		return 0;
	int sign=1,base=0,i=0,n=str.size();
	
	while(i<n && str[i]==' ')//判断空格
		++i;
	
	if(i<n && (str[i]=='+'||str[i]=='-'))//判断符号
	{
		sign = (str[i++]=='+')?1:-1;
	}
	
	while(i<n && str[i]>='0' && str[i]<='9')//如果第一个字符不是数字，返回0，否则转为整型保存下来
	{
		if(base>INT_MAX/10 || (base==INT_MAX/10 && str[i]-'0'>7))
			return sign==1?INT_MAX:INT_MIN;
		base = 10*base+(str[i++]-'0');
	}
	return sign*base;
}
