/*
* @author：sunny
* Description：排序算法总结
* Content：1-冒泡排序、2-快速排序
*/

/**冒泡排序**/

void BubbleSort(int *a,int N)
{
	for(int i=0;i<N-1;++i)   //外循环次数
	{
		for(int j=0;j<N-1-i;++j)//内循环趟数
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}	
}

/**快速排序**/

void QuickSort(int *a,int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot=Partion(a,low,high);//一次分治，找出枢轴值位置，将数组一分为二
		QuickSort(a,low,pivot-1);
		QuickSort(a,pivot+1,high);
	}
}

//将选取的pivotkey不断交换，将比他小的换到它的左边，比他大的换到右边，在交换中不断变换自己的位置
int Partion(int *a,int low,int high)
{
	int pivotkey=a[low];//用子表的第一个值作枢轴
	while(low<high)
	{
		while(low<high && a[high]>pivotkey)
			--high;
		swap(a[low],a[high]);
		
		while(low<high && a[low]<pivotkey)
			++low;
		swap(a[low],a[high]);
	}
	return low;//返回枢轴所在位置
}

