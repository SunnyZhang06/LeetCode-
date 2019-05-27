/*
* @author：sunny
* 295、寻找中位数
* https://leetcode-cn.com/problems/find-median-from-data-stream/
* 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/	

/*
* 思路：建立两个堆：一个大根堆，保存所有整数中较小的1/2;一个小根堆，保存所有整数中较大的1/2;
*   并且，依次添加元素过程中，两个堆大小的差的绝对值不能超过1； 		  
*/

class MedianFinder {

private:
    priority_queue<int> heap1;//默认，大根堆
    priority_queue<int,vector<int>,greater<int>> heap2;//小根堆（升序序列）
	
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) 
	{        
        //第一元素加入大根堆
        if(heap1.size()==0){
            heap1.push(num);
            return;
        }
        
        if(num<=heap1.top()){
            //第二个元素比大根堆的顶小
            heap1.push(num);
                
             //大根堆元素过多
            if(heap1.size()-heap2.size()>1)
            {
                int temp = heap1.top();
                heap1.pop();
                heap2.push(temp);//大根堆弹出顶到小根堆     
            }
            
        }
        else{
            //第二个元素比大根堆的顶大，直接进入小根堆
            heap2.push(num);
            
            //小根堆元素过多
            if(heap2.size()-heap1.size()>1)
            {
                int temp = heap2.top();
                heap2.pop();
                heap1.push(temp);//小根堆弹出顶到大根堆 
            }
        }
        
    }
    
    double findMedian() {
        //输入的元素为奇数个
        if(heap1.size() > heap2.size())
            return heap1.top();
        else if(heap1.size() < heap2.size())
            return heap2.top();
        
        //输入的元素个数为偶数
        else
            return (heap1.top()+heap2.top())/2.0; //取大根堆、小根堆的堆顶元素取平均值，即为所求全局中位数
           
    }
    
};

