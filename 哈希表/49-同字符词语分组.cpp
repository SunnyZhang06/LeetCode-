
9//49同字符词语分组（数组哈希）

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	//由于错位词重新排序后都会得到相同的字符串，以此作为key，将所有错位词都保存到字符串数组中，建立key和字符串数组之间的映射，最后再存入结果res中即可以
	int n=strs.size();
	vector<vector<strint>> res;
	unordered_map<string,vector<string>> m;
	for(string str:strs)
	{
		string t=str;
		sort(t.begin(),t.end());
		m[t].push_back(str);	
	}
	for(auto a:m)
		res.push_back(a->second);
	return res;
	
	//不用排序，用一个大小为26的int数组来统计每个单词中字符出现的次数，然后将int数组转为一个唯一的字符串
	//跟字符串数组进行映射
	
	for(str:strs)
	{
		vector<int> cnt(26,0);
		string t="";
		for (char c:str) ++cnt[c-'a'];
		for(int d:cnt)
			t+=to_string(d)+"/";
		m[t].push_back(str);
	}
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































