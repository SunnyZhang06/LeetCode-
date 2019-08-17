/*
* @author：sunny
* 217、存在重复元素
* https://leetcode-cn.com/problems/contains-duplicate/
* 给定一个整数数组，判断是否存在重复元素。
*/

/*
* 方法1：用 set
* 思路：如果字符没出现过就加入到集合中，如果出现过就返回true；
*/

bool containsDuplicate(vector<int>& nums)
{
	unordered_set<int> set;
	for(auto num:nums)
	{
		if(st.count(num))
			return true;
		st.insert(num);
	}
	return false;
}

/*
* 方法2：用 map 建立数字到出现次数的映射 
* 思路：map统计每个数字出现的次数，{num：count}
*/
bool containsDuplicate(vector<int>& nums)
{
	unordered_map<int,int> m;
	for(auto num:nums)
	{
	 if(m.find(num)!=m.end())//查找是否出现过,或写成 if(m.count(num))
		 return true;
	 ++m[num];//记录nums[i]及其出现的次数
	}
	return false;
}
