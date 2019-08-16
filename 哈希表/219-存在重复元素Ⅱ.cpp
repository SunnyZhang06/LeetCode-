
6//219存在重复元素Ⅱ

//判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
 bool containsNearbyDuplicate(vector<int>& nums, int k)
 {
	 //map统计每个数字出现的位置，{num：postion}
	 unordered_map<int,int> m;
	 for(int i=0;i<nums.size();++i)
	 {
		 if(m.find(nums[i])!=nums.end() && i-m[nums[i]]<=k)//如果找到相同num，且位置差的绝对值不超过k
			 return true;
		 else
			 m[nums[i]]=i;//没找到时就依次记录出现的num和它的位置
	 }
	 return false;
 }
