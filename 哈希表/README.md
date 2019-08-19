### 基础知识

1、哈希表概念
  - 哈希表也叫散列表，是根据key直接访问value在内存存储位置的数据结构
  - key——映射——value，这个映射函数叫做散列（哈希）函数

2、 解决散列冲突的方法
  - 开放寻址法：线性探测、二次探测
  - 链表法

3、C++中的关联式容器
  - map、set——根据元素键值自动排序，不允许有相同的键值，**底层红黑树（RBTree）实现**
  - multiset、multimap——允许键值重复，**底层红黑树（RBTree）实现**
  - unorderedmap、unorderedset——不自动排序，无重复的键值，**底层哈希表（hashtable）实现**
  - 使用**count**函数，返回被查找元素的个数。有则返回1，无则返回0（map/set中不存在相同元素，所以返回值只能是1或0）
  - 使用**find**函数，返回的是被查找元素的位置（迭代器），没有则返回map.end()
  
4、编程题中遇到的问题大多可以转化为 **建立元素到元素出现位置或次数映射关系**的问题


### 目录

- [1-两数之和](http://t.cn/AiHOuYLt)（easy 【元素和出现位置映射关系】）
- [3-无重复字符的最长子串](http://t.cn/AiHO3muG)（medium 【元素和出现位置映射关系】）
- [49-同字符词语分组](http://t.cn/AiHOrVJL)（medium 【元素和元素数组映射关系】）
- [187-重复的DNA序列](http://t.cn/AiHOrQGv)（medium 【字符串哈希】）
- [202-快乐数](http://t.cn/AiHOdPcy)（easy）
- [205-同构字符串](http://t.cn/AiHOdNxd)（easy 【元素和出现位置映射关系】）
- [217-存在重复元素](http://t.cn/AiHOgf3q)（easy 【元素和出现次数映射关系】）
- [219-存在重复元素Ⅱ](http://t.cn/AiHOeiBO)（easy 【元素和出现位置映射关系】）
- [242-有效的字母异位词](http://t.cn/AiHODiPG)（easy 【元素和出现次数映射关系】）
- [290-词语模式](http://t.cn/AiHOkZMu)（easy 【元素和出现位置映射关系】）
- [387-字符串中的第一个唯一字符](http://t.cn/AiHOkNxN)（easy 【元素和出现次数映射关系】）
- [409-最长回文串](http://t.cn/AiHOkBg7)（easy 【元素和出现次数映射关系】）
