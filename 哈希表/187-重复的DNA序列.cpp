
11//187重复的DNA序列（字符串哈希）

vector<string> findRepeatedDnaSequences(string s) {
	
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
































