/*
* @author：sunny
* Description：排序算法总结
* Content：归并排序
*/

/**归并排序**/

void MergeSort(int *a, int low, int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;    //从中间划分两个子序列
		MergeSort(a, low, mid);  //对左侧子序列进行递归排序
		MergeSort(a, mid+1, high);//对右侧子序列进行递归排序
		merge(a, low, mid, high);//将前后相邻的两个有序表合并为一个有序表
	}
}

void merge(int *a,int low, int mid, int high)
{
	int i,j,k;
	int b[high+1]={0};//辅助空间
	for(k=low; k<=high; k++)//将a中所有元素复制到b中
		b[k]=a[k];
	for(i=low, j=mid+1,k=i;i<=mid&&j<=high;k++)
	{
		if(b[i]<b[j]) //比较b的左右两段中的元素，将较小值复制到a中
			a[k]=b[i++];
		else
			a[k]=b[j++];
	}
	while(i<=mid)     //若第一个表未检测完，复制
		a[k++]=b[i++];
	while(j<=high)    //若第二个表未检测完，复制
		a[k++]=b[j++];	
}





