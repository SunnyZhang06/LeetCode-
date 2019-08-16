//哈希表——散列表，根据key直接访问在内存存储位置的数据结构，key——映射——value，这个映射函数叫做散列（哈希）函数
//解决散列冲突：1）开放寻址法：线性探测、二次探测	2）链表法（拉链法）

1//1两数之和

vector<int> twoSum(vector<int>& nums, int target) 
{
	
	/*
	unordered_map<int, int> m;
	vector<int> res;
	for(int i=0;i<nums.size();i++)
	{
		if(m.count(target-nums[i]))
		{
			res.push_back(m[target-nums[i]]);
			res.push_back(i);
			//return {m[target-nums[i]],i};
		}
		m[nums[i]] = i;
	}
		return res;
		*/
	vector<int> res;

	for(int i=0;i<nums.size();++i)
	{
		auto it=find(nums.begin()+i+1,nums.end(),target-nums[i]);
		if(it!=nums.end())//找到
		{
			res.push_back(i);
			res.push_back(distance(nums.begin(),it));
			break;
		}
	}       

	return res;	
}

12//76最小窗口子串（哈希维护窗口）

string minWindow(string s, string t)
{
	////HashMap统计字符出现的位置 {letter:cnt}
	string res="";
	unordered_map<char,int> letterCnt;
	int left=0,cnt=0,minLen=INT_MAX;
	for(char c:t) 
		++letterCnt[c];
	}
}































