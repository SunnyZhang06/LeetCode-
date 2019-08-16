

3//202快乐数

bool isHappy(int n) 
{	
	//规律：往后面计算会出现重复数字，快乐数重复1，非快乐数重复其他数字
	//用HashSet来记录所有出现过的数字，然后每出现一个新数字，在HashSet中查找是否存在，若不存在
	//则加入表中，若存在则跳出循环且判断此数是否为1
	
	unordered_set<int> st;
	while(n!=1)
	{
		int sum=0;
		while(n)
		{
			sum+=(n%10)*(n%10);//从高位往低位计算平方和
			n/=10;
		}
		n=sum;
		if(st.count(n))
			break;
		st.insert(n);
	}
	return n==1;
	
	//也可以不用HashSet，非快乐有个特点，循环的数字中必定会有4（这里不证明）
	
	while(n!=1 && n!=4)
	{
		int sum=0;
		while(n)
		{
			sum+=(n%10)*(n%10);
			n/=10;
		}
		n=sum;
	}
	return n==1;
	
	
}