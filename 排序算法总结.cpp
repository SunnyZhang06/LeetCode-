//参考：https://blog.csdn.net/opooc/article/details/80994353
//      https://blog.csdn.net/hellozhxy/article/details/79911867
/*
十大排序算法分类：
				|插入排序类：直接插入:将一个记录插入到已经排好序的有序表中
				|			 希尔排序：跳跃分割，局部基本有序
				|选择排序类：简单选择排序:找到合适的关键字再交换
	比较类排序	|			 堆排序:
				|交换排序类：冒泡排序：外循环次数，内循环趟数
				|			 快速排序：一分为二，一大一小
				|归并排序类：两路归并：假定待排序表含有n个记录，则可以视为n个有序的子表，每个子表长度为1，然后两两归并
							 多路归并：
							
				|计数排序
	非比较排序	|桶排序      https://blog.csdn.net/sb985/article/details/79921571
				|基数排序
*/

#include <iostream>

using namespace std;

/*直接插入*/
void ins(int *a, int N)
{
	int i,j,tmp;
	
	for(int i=1;i<N;i++)
	{
		if(a[i]<a[i-1])//需要插入
		{
			tmp=a[i];
			for(j=i-1;a[j]>tmp && j>=0;j--)
				a[j+1]=a[j];//往后移动
			a[j+1]=tmp;
		}			
	}
}

/*希尔排序*/
void hill(int *a, int N)
{
	int i,j,tmp,dk;
	
	for(dk=N/2;dk>=1;dk=dk/2)
	{
		for(i=dk;i<N;i++)
		{
			if(a[i]<a[i-dk])//需要插入
			{
				tmp=a[i];
				for(j=i-dk;a[j]>tmp&&j>=0;j-=dk)
					a[j+dk]=a[j];
				a[j+dk]=tmp;
			}
			
		}
	}
}

/*选择排序*/
void slect(int *a, int N)
{
	int i,j,min,tmp;

	for(i=0;i<N;i++)
	{
		min=i;//假设当前值a[i]为最小值，对应的下标为i
		for(j=i+1;j<N;j++)
		{
			if(a[j]<a[min])//如果遇到比当前下标对应值更小的，则交换下标
                min=j;
		}
		if(min!=i)
			swap(a[min],a[i]);//循环结束，一定可以找到最小值对应的下标，将其与a[i]交换
	}

}

/*堆排序*/
void HeapSort(int *a, int N)
{
	int i;
	//构建大顶堆
	for(i=N/2;i>0;i--)//从i=[N/2]-1反复调整堆
		HeapAdjust(A,i,N);
	
	//
	for(i=N;i>1;i--)
	{
		swap(a[i],a[1]);
		HeapAdjust(A,1,i-1);
	}	
}

void HeapAdjust(int a[],int k,int len)
{
	a[0]=a[k];   //a[0]暂存
	for(int i=2*k;i<len;i*=2)
	{
		if(i<len && a[i]<a[i+1])//左孩子结点的值小于右孩子结点的值
			i++;
		if(a[0]>a[i])//父结点大于孩子结点的值直接跳出
			break;
		a[k]=a[i];//将a[i]调整到双亲结点上
		k=i;      //修改k值，继续向下调整
	}
	a[k]=a[0];
}

/*冒泡排序*/
void bubble(int *a, int N)
{
    for(int i=0;i<N-1;i++)//外循环次数
    {
        for(int j=0;j<N-i-1;j++//内循环趟数
        {
            if(a[j+1]<a[j])
            {
                int tmp=a[j+1];
                a[j+1]=a[j];
                a[j]=tmp;
            }
        }
    }
}

/*快速排序*/
void QuickSort(int a[], int low, int high)
{
	int pivot;
	if(low<high)
	{
		pivot=Partion(a[], low, high);//一次分治，找出枢轴值位置，将数组一分为二
		QuickSort(a, low, pivot-1);
		QuickSort(a, pivot+1,high);
	}	
}
//将选取的pivotkey不断交换，将比他小的换到它的左边，比他大的换到右边，在交换中不断变换自己的位置

int Partion(int a[], int low, int high)
{
	int pivotkey=a[low];//用子表的第一个作枢轴
	while(low<high)
	{
		while(low<high && a[high]>pivotkey)
			high--;
		swap(a[low], a[high]);
		
		while(low<high && a[low]<pivotkey)
			low++;
		swap(a[low],a[high]);
	}
	
	return low;//返回枢轴所在位置
	
}

/*归并排序*/
void MergeSort(int a[], int low, int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;//从中间划分两个子序列
		MergeSort(a, low, mid);  //对左侧子序列进行递归排序
		MergeSort(a, mid+1, high);//对右侧子序列进行递归排序
		merge(a, low, mid, high);//归并
	}
}

void merge(int a[],int low, int mid, int high)
{
	int i,j,k;
	int b[high+1]={0};//辅助空间
	for(k=low; k<=high; k++)
		b[k]=a[k];
	for(i=low, j=mid+1,k=i;i<=mid&&j<=high;k++)
	{
		if(b[i]<b[j])
			a[k]=b[i++];
		else
			a[k]=b[j++];
	}
	while(i<=mid)     //若第一个表未检测完，复制
		a[k++]=b[i++];
	while(j<=high)    //若第二个表未检测完，复制
		a[k++]=b[j++];	
}




