### 堆的相关知识
在STL中，堆是用priority_queue实现的，其模板声明带有三个参数：
`priority_queue(Type, Container, Functional)`
- 其中 Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
- Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
- STL里面默认用的是 vector ,比较方式默认用 operator< , 所以如果你把后面俩个参数缺省的话，优先队列就是**大顶堆**，队头元素最大。

如果要用到**小顶堆**，则一般要把模板的三个参数都带进去。STL里面定义了一个仿函数 greater<>，对于基本数据类型可以用这个仿函数声明小顶堆：`priority_queue(int, vector<int>, greater<int>) q;`

对于自定义类型，则必须自己重载 operator< 或者自己写仿函数(自定义比较方式)
```
struct Node
{
	int x,y;
	Node(int a=0,b=0):x(a),y(b){}
}
/* 重载 < */
bool operator<(Node a,Node b)
{
	if(a.x == b.x)
		return a.y > b.y;
	return a.x > b.x;
}

priority_queue<Node> q;

/*自定义*/
struct cmp
{
	bool operator() ( Node a, Node b )
	{
		if( a.x== b.x ) 
			return a.y> b.y;         
        return a.x > b.x; 
	}
}

priority_queue<Node, vector<Node>, cmp> q;
```
**参考文章：**<br></br>
1、[https://www.cnblogs.com/Fresh--air/p/6705878.html](https://www.cnblogs.com/Fresh--air/p/6705878.html)<br></br>
2、[https://www.cnblogs.com/flyoung2008/articles/2136485.html](https://www.cnblogs.com/flyoung2008/articles/2136485.html)

### 目录
- [23-合并K个排序链表](http://t.cn/AiHOsbbR)（hard  小顶堆）
- [215-数组中第K大的数](http://t.cn/AiHOs954)（medium  小顶堆）
- [295-寻找中位数](http://t.cn/AiHOsnrc)（hard  大顶堆、小顶堆）
- [703-数据流中的第K大元素](http://t.cn/AiHWvLGr)（easy  小顶堆）
