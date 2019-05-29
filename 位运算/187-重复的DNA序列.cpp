/*
* @author：sunny
* 187、重复的DNA序列
* https://leetcode-cn.com/problems/repeated-dna-sequences/
* 所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。
* 编写一个函数来查找 DNA 分子中所有出现超多一次的10个字母长的序列（子串）。
*/	

/*
* 思路1：将DNA序列进行整数编码，用两位来表示一个字符，00表示A，01表示C，10表示G，11表示T，那么我们总共需要20位就可以表示十个字符流。
*/

vector<string> findRepeatedDnaSequences(string s) 
{	
    unordered_set<string> res;
    unordered_set<int> st;
	unordered_map<int,int> m{{'A',0},{'C',1},{'G',2},{'T',3}};
	int cur = 0;
	for(int i=0;i<9;++i)
		cur = cur<<2 | m[s[i]];//先把前9个字符对应的编码读进来
	for(int i=9;i<s.size();++i)
	{
		cur = ((cur&0x3ffff)<<2) | (m[s[i]]);//先取出之前编码的后18位(9个字符)，然后每次读进来一个新的字符，把其2位编码加到cur后面，这样共20位。
		if(st.count(cur))
			res.insert(s.substr(i-9,10));
		else
			st.insert(cur);
	}
	return vector<string>(res.begin(),res.end());
}


/*
* 思路2：如果不需要考虑节省内存空间，可以直接将10个字符组成字符串存入set中，那么也就不需要mask了。
*/

vector<string> findRepeatedDnaSequences(string s) 
{	
	set<string> res,st;
	for(int i=0;i+9<s.size();++i)
	{
		string t=s.substr(i,10);//每次截10个字母
		if(st.count(t))//如果出现过，则保存到结果集合中
			res.insert(t);
		else
			st.insert(t);//如果没出现过，则加入到另外一个集合中
	}
	
	return vector<string>{res.begin(),res.end()};        
}