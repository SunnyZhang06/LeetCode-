/*
* @author：sunny
* 344、翻转字符串
* https://leetcode-cn.com/problems/reverse-string/
* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
* 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
*/	

/*
* 思路：双指针法，一个指向头，一个指向尾，两两交换。
*/

void reverseString(vector<char>& s)
{
	int left=0,right=s.size()-1;
	
	while(left<right)
		swap(s[left++],s[right--]);
}

/*另外一种写法*/
void reverseString(vector<char>& s)
{
	int len = s.size();
	int j = len - 1;
	for (int i = 0; i < len / 2; i++)
		swap(s[i], s[j--]);
}


