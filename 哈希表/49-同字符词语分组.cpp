/*
* @author：sunny
* 49、同字符词语分组（字母异位词分组）
* https://leetcode-cn.com/problems/group-anagrams/
* 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
*/

/*
* 方法1：使用HashMap来建立key和字符串数组之间的映射
* 思路：由于错位词重新排序后都会得到相同的字符串，故以此作为key，将所有错位词都保存到字符串数组中，
*       建立key和字符串数组之间的映射，最后再存入结果res中即可。
*/

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<strint>> res;
	unordered_map<string,vector<string>> m;
	for(string str:strs)
	{
		string t=str;
		sort(t.begin(),t.end());
		m[t].push_back(str);	//以排序后的相同字符串为key
	}
	for(auto a:m)
		res.push_back(a.second);
	return res;
} 

/*
* 方法2：利用26个字母特点建立映射关系
* 思路：不用排序，用一个大小为26的int数组来统计每个单词中字符出现的次数，然后将int数组
*       转为一个唯一的字符串,跟字符串数组进行映射。
*/

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> res;
	unordered_map<string,vector<string>> m;
	for(str:strs)
	{
		vector<int> cnt(26,0);
		string t="";
		for (char c:str) 
			++cnt[c-'a'];
		for(int d:cnt)
			t+=to_string(d)+"/";
		m[t].push_back(str);
	}
	for(auto a:m)
		res.push_back(a.second);
	return res;
}
