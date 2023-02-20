#include<stdio.h>

int main()
{
    int s,item;
    
    printf("Enter the size of the array:");
    scanf("%d",&s);

    int arr[s];
    printf("\nEnter the array in sorted order:");
    for(int i=0; i<s; i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to be searched: \n");
    scanf("%d",&item);
    int index=-1,high=s,low=0,mid;

    while(low<=high)
    {
        mid=(high+low)/2;
        if(arr[mid]==item)
            {
                printf("Element found at index: %d\n",mid);
                index = mid;
                break;
            }
        else if(item>arr[mid])
            low=mid+1;
        else 
            high=mid-1;
        

        
    }
    if(index==-1)
        {
            printf("Entered element not found");
        }

        return 0;

}