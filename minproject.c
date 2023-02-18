#include<stdio.h>
#include<stdlib.h>
int N,*arr;
int partition(int a[],int low, int up)
{
    int t,i,j,v;
    i = low+1;
    j=up;
    v=a[low];
    while(i<=j)
    {
        while(a[i]<v && i<up)
            i++;
        while(a[j]>v)
            j--;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
        else
            i++;
    }
    a[low]=a[j];
    a[j]=v;
    return j;            
}
void quicksort(int *a,int p,int q)
{   int v;
    if(p>=q) 
        return;
    v=partition(a,p,q);
    quicksort(a,p,v-1);
    quicksort(a,v+1,q);    
}
void Merge(int *L,int *R,int nL,int nR,int *b)
{
    int i=0,j=0,k=0;
    while(i<nL && j<nR)
    {
        if(L[i]<=R[j])
        {   b[k]=L[i];
            i++;
        } 
       else
        {   b[k]=R[j];
            j++;
        } 
    k++; 
    }//merging the left and right subarrays
    while(i<nL)
    {   b[k]=L[i];
        i++;
        k++;
    }//when right array is exhausted
    while(j<nR)
    {   b[k]=R[j];
        j++;  
        k++;
    }//when left array is exhausted

}
void Mergesort(int *b,int n)
{   int mid;
    if(n<2)
    return;//base condition
    mid =n/2;
    int left[mid],right[n-mid];//creating the two subarrays
    for(int i=0;i<mid;i++)
        left[i]=b[i];
    for(int i=mid;i<n;i++)
        right[i-mid]=b[i];
    Mergesort(left,mid);//sorting the left subdivision
    Mergesort(right,n-mid);//sorting the right subdivision
    Merge(left,right,mid,n-mid,b);//merging the left and right subdivision
}
void insertsort(int *a,int n)
{
    int temp;
    for(int i=1; i<n;i++){
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{   
    int ch,tr=1;
    printf("Enter the size of the array: \n");
    scanf("%d",&N);
    arr =(int *)malloc((N)*sizeof(int));
    printf("Enter the elements of the array: \n");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Press 1 to perform Quicksort\n  2 for Mergesort\n   3 for Insertion sort: \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            quicksort(arr,0,N-1);
            break;
        case 2:
            Mergesort(arr,N);
            break;
        case 3:
            insertsort(arr,N);
            break;
        case 4:
             printf("Wrong choice \n");
        
    }   

printf("The sorted array is: \n");
for(int i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }

}