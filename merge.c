#include<stdio.h>
#include<stdlib.h>

merging(int a[],int left,int mid, int right)
{
	int a_temp[104];
	int b_temp[104];
	int p=0;
	int q=0;
	for(int i=left ; i<=mid;i++)
	{
		a_temp[p]=a[i];
		p++;
	}
	a_temp[p]=999;
	for(int j=mid+1;j<=right;j++)
	{
		b_temp[q]=a[j];
		q++;
	}
	b_temp[q]=999;
	
	int r=0,s=0;
	while(a_temp[r] != 999 || b_temp[s] !=999)
	{
		if(a_temp[r]>=b_temp[s])
		{
			a[left]=b_temp[s];
			s++;
			left++;
		}		
		else
		{
			a[left]=a_temp[r];
			r++;
			left++;
	
		}		

	}

	if(a_temp[r]==999)
	{
		while(b_temp[s]!=999)
		{
			a[left]=b_temp[s];
			s++;
		}
	}
	else if(b_temp[s]==999)
	{
		while(a_temp[r]!=999)
		{
			a[left]=a_temp[r];
			r++;
		}

	}



}

print_array(int a[], int size)
{
	printf("\n Sorted list is - \n");
	for(int i=0;i<=size-1;i++)
	{
		printf(" %d  ",a[i]);
		//printf("\n");
	}


}



merge_sort(int a[],int left, int right)
{
	printf("left is - %d , right is -%d \n",a[left] , a[right]);
	//printf("%d",a[left],a[right]);
	if(left<right)
	{
		
	
	
	int mid=(left+right)/2;
	merge_sort(a,left,mid);
	merge_sort(a,mid+1,right);
	merging(a,left,mid,right);


	}

}
void main()
{
	int a[]={2,8,6,5,9,1};
	int arr_size=sizeof(a)/sizeof(a[0]);
	merge_sort(a,0,arr_size-1);
	print_array(a,arr_size);

}








