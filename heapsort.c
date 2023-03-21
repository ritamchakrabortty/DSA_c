#include<stdio.h>
#include<stdlib.h>
void swap(int *i,int *j)
{
	int temp =*i;
	*i=*j;
	*j=temp;
}
void heapify(int *arr,int N,int k)
{
	int largest=k;
	int left=2*k+1;
	int right=2*k+2;
	if(left<N && arr[left]>arr[largest])
		largest=left;
	if(right<N && arr[right]>arr[largest])
		largest=right;
	if(largest != k)
	{
		swap(&arr[k],&arr[largest]);
		heapify(arr,N,largest);
	}
}

void heapsort(int *arr,int N)
{
	for(int i=N/2-1;i>=0;i--)
		heapify(arr,N,i);
	for(int i=N-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

int main()
{
    int *arr,N;
    printf("Enter the size of the array: ");
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    printf("Enter the elements: \n");
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
	heapsort(arr,N);
	printf("The sorted array is: \n");
	for(int i=0;i<N;i++)
		printf("%d ",arr[i]);
		
	return 0;
}