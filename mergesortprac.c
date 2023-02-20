#include<stdio.h>
#include<stdlib.h>
void merge(int *L, int *R, int nL, int nR,int *a)
{   
    int i=0,j=0,k=0;
    while(i<nL && j<nR)
    {
        if(L[i]<R[j])
        {
        a[k] = L[i];
        i++;
        
        }
        else
        {
            a[k] = R[j];
            j++;
            
        }
        k++;
    }
    while(i<nL)
    {
      a[k] = L[i];
        i++;
        k++;  
    }
    while(j<nR)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *a, int N)
{ if(N<2)
    return;
  int mid = N/2;
  int L[mid],R[N-mid];
  for(int k=0;k<mid;k++)
    {
        L[k] = a[k];
    }
  for(int p=mid;p<N;p++)
    {
        R[p-mid] = a[p];

    }
mergesort(L,mid);
mergesort(R,N-mid);
merge(L,R,mid,N-mid,a);  
      



}

int main()
{
    int N;
    printf("Enter the size of the array:");
    scanf("%d", &N);
    int *a;
    a = (int *)malloc(N*sizeof(int));
    printf("Enter the elements of the array:");
    for(int i=0; i<N; i++)
        {
            scanf("%d",&a[i]);

        }
    mergesort(a,N);
    printf("\n");
    printf("The sorted array is:");
    for(int i=0; i<N; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}