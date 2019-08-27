/*
* @author：sunny
* Description：排序算法总结
* Content：1-简单选择、2-堆排序
*/

/**简单选择**/

void SelectSort(int *a,int N)
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

/**堆排序**/
//建堆复杂度O(n)

void HeapSort(int *a, int N)
{
	int i;
	//构建大顶堆(初始化大顶堆，是从最后一个有子节点的结点开始往上调整最大堆)
	for(i=N/2;i>0;i--)//从i=[N/2]-1反复调整堆
		HeapAdjust(a,i,N);
	
	//排序
	for(i=N;i>1;i--)
	{
		swap(a[i],a[1]);//交换堆顶a[1]和未排序序列的最后一个元素a[i]
		HeapAdjust(a,1,i-1);//将a[1]——a[i-1]重新调整为大顶堆
	}	
}

void HeapAdjust(int *a,int k,int len)
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




