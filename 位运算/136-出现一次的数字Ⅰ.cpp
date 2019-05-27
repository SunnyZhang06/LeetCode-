/*
* @author：sunny
* 136、出现一次的数字Ⅰ
* https://leetcode-cn.com/problems/single-number/
* 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
*/	

/*
* 思路1：采用异或方法(相同为0，不同为1)，将数组里面的元素异或一遍，相同的两个数会异或为0，只留下出现一次的那个数，n与0相或保留原值
*/


int singleNumber(vector<int>& nums)
{
	int res=0;
	for(auto num:nums)
		res^=num;	
	return res;	
}

/*
* 思路2：利用Hashset。遍历数组中的每个数字，若当前数字已经在 HashSet 中了，则将 HashSet 中的该数字移除，否则就加入 HashSet。
*/

int singleNumber(vector<int>& nums)
{
	unordered_set<int> st;
	for(auto num:nums)
	{
		if(st.count(num))
			st.erase(num);
		else
			st.insert(num);
	}	
	return *st.begin();	
}