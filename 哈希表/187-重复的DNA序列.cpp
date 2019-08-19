/*
* @author：sunny
* 187、重复的DNA序列（字符串哈希）
* https://leetcode-cn.com/problems/repeated-dna-sequences/
* 所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，
* 识别 DNA 中的重复序列有时会对研究非常有帮助。编写一个函数来查找 DNA 分子中所有出现超多
* 一次的10个字母长的序列（子串）。
*/

/*
* 方法1：使用set
* 思路：遍历给定的字符串，每次截10个字母的连续子串，如果出现过，则保存到结果集合中。
*/

vector<string> findRepeatedDnaSequences(string s) {
	
	set<string> res,st;
	for(int i=0;i+9<s.size();++i)
	{
		string t=s.substr(i,10);//每次截10个字母
		if(st.count(t))
			res.insert(t);
		else
			st.insert(t);//如果没出现过，则加入到另外一个集合中
	}	
	return vector<string>{res.begin(),res.end()};        
}
































