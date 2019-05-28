
5//201数字范围按位与

int rangeBitwiseAnd(int m, int n)
{
	//每次去掉最低位的1，如果小于等于m，返回此时的n
	//5(0101),6(0110),7(0111),三个数字按位与结果4（0100）
	while(m<n)
		n=n&(n-1);
	return n;
	
	//平移m和n直到相等
	//m=5(0101),n=7(0111),相等时：m=n=0001,i=2
	int i=0;
	while(m!=n)
	{
		m>>=1;
		n>>=1;
		i++;
	}
	return (m<<i);
}

