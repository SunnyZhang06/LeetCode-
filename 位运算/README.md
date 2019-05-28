### 位操作相关知识 

位的基本操作如下：  

**1、按位与运算（&）**

特点：“同1为1，其他为0”

用途：1）清零。如果想将一个单元清零，即使其全部二进制位为0，只要与一个各位都为零的数值相与，结果为零。<br></br>
　　　2）取一个数中指定位。找一个数，对应X要取的位，该数的对应位为1，其余位为零，此数与X进行“与运算”可以得到X中的指定位。

**2、按位或运算（|）**

特点：“有1出1，全0为0”

用途：常用来对一个数据的某些位置1。

例如：将X=10100000的低4位置1 ，用 X | 0000 1111 = 1010 1111 即可得到。

**3、异或运算符（^）**

特点：“相同为0，不同为1”

用途：1）、使特定位翻转找一个数，对应X要翻转的各位，该数的对应位为1，其余位为零，此数与X对应位异或即可。<br></br>
　　　　　　例：X=10101110，使X低4位翻转，用X ^0000 1111 = 1010 0001即可得到。<br></br>
　　　2）、与0相异或，保留原值 ，X ^ 00000000 = 1010 1110。

**4、取反运算符（~）**

**5、左移运算符（<<）**

若左移时舍弃的高位不包含1，则每左移一位，相当于该数乘以2。

**6、右移运算符（>>）**

操作数每右移一位，相当于该数除以2。

**参考文章：**
1、[https://blog.csdn.net/xiaopihaierletian/article/details/78162863](https://blog.csdn.net/xiaopihaierletian/article/details/78162863)


### 目录

- [136-出现一次的数字Ⅰ](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/136-%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97%E2%85%A0.cpp)（easy）
- [137-只出现一次的数字 II](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/137-%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97II.cpp)（easy）
- [187-重复的DNA序列]()（easy）
- [190-颠倒二进制位](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/190-%E9%A2%A0%E5%80%92%E4%BA%8C%E8%BF%9B%E5%88%B6%E4%BD%8D.cpp)（easy）
- [191-位1的个数](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/191-%E4%BD%8D1%E7%9A%84%E4%B8%AA%E6%95%B0.cpp)（easy）
- [201-数字范围按位与](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/201-%E6%95%B0%E5%AD%97%E8%8C%83%E5%9B%B4%E6%8C%89%E4%BD%8D%E4%B8%8E.cpp)（easy）
- [231-2的幂](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/231-2%E7%9A%84%E5%B9%82.cpp)（easy）
- [260-只出现一次的数字 III](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/260-%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97III.cpp)（easy）
- [268-缺失数字](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/268-%E7%BC%BA%E5%A4%B1%E6%95%B0%E5%AD%97.cpp
)（easy）
- [342-4的幂](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/342-4%E7%9A%84%E5%B9%82.cpp)（easy）
- [371-两整数之和](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/371-%E4%B8%A4%E6%95%B4%E6%95%B0%E4%B9%8B%E5%92%8C.cpp)（easy）
- [461-汉明距离](https://github.com/SunnyZhang06/LeetCode-solution-by-classification/blob/master/%E4%BD%8D%E8%BF%90%E7%AE%97/461-%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB.cpp)（easy）
