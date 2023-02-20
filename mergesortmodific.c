#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int n)
{
	int i,j,k,l1,u1,l2,u2,s=1;
	int aux[n];
	int *p1,*p2, *t;
	p1 = &a[0];
	p2 = &aux[0];

	while(s<n)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	{
		l1=0;
		k=0;
		while(l1+s < n)
		{
			l2 = l1+s;
			u1 = l2-1;
			u2 = (l2+s-1<n)?(l2+s-1):(n-1);
			for(i=l1,j=l2;i<=u1 && j<=u2;k++)
			{
				if(p1[i]<p1[j])
					p2[k]=p1[i++];
				else
					p2[k]=p1[j++];
			}
			for(;i<=u1;k++)
				p2[k]=p1[i++];
			for(;j<=u2;k++)
				p2[k]=p1[j++];
			l1=u2+1;
		}
		for(i=l1;i<n;i++)
			p2[k++]=p1[i];
		
		t=p1;
		p1=p2;
		p2=t;

		s=s*2;
	}
}

int main()
{
	int n,i;
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	int arr[n];

	for(i=0;i<n;i++)
	{
		printf("Enter element %d:\n",i);
		scanf("%d",&arr[i]);
	}

.
	merge(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	return 0;
}