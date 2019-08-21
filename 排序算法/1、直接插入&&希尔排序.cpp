/*
* @author：sunny
* Description：排序算法总结
* Content：1-直接插入、2-希尔排序
*/

/**直接插入**/

void InsertSort(int *a,int N)
{
	for(int i=1;i<N;++i)  
	{
		if(a[i]<a[i-1])//需要插入(因为前面已有序)
		{
			int temp=a[i];
			for(int j=i-1;j>=0 && a[j]>temp;--j)
				a[j+1]=a[j];//往后移动
			a[j+1]=temp;
		}
	}	
}

/**希尔排序**/

void HillSort(int *a,int N)
{
	int dk;
	for(dk=N/2;dk>=1;dk/=2)
	{
		for(int i=dk;i<N;++i)  
		{
			if(a[i]<a[i-dk])//需要插入(因为前面已有序)
			{
				int temp=a[i];
				for(int j=i-dk;j>=0 && a[j]>temp;j-=dk)
					a[j+dk]=a[j];//往后移动
				a[j+dk]=temp;
			}
		}
	}	
}