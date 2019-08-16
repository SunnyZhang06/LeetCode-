
5//217存在重复元素
//如果任何值在数组中出现至少两次，函数返回 true

 bool containsDuplicate(vector<int>& nums)
 {
	//map统计每个数字出现的次数，{num：count}
	unordered_map<int,int> m;
	 for(int i=0;i<nums.size();++i)
	 {
		 if(m.find(nums[i])!=m.end())//查找是否出现过
			 return true;
		 ++m[nums[i]];//记录nums[i]及其出现的次数
	 }
	 return false;
 }
