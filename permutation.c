/** Code to enter n number of strings and print all possible permutations of those strings
Eg: Enter the number of strings 
3
Enter the strings 
abcde
pqrst
vwxyz

Output:

abcde pqrst vwxyz 
abcde vwxyz pqrst 
pqrst abcde vwxyz 
pqrst vwxyz abcde 
vwxyz pqrst abcde 
vwxyz abcde pqrst */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char **x,char **y)
{ char *t;
t=*x;
*x=*y;
*y=t;
}
void display(char *ptr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%s ",ptr[i]); 
    printf("\n");
    
}
void permute(char *a[],int l,int r,int n)
{  
    if(l==r)
      { display(a,n);
        return;
      }
    for(int i=l;i<=r;i++)
    {   
        swap(&a[l],&a[i]);
        permute(a,l+1,r,n);        
        swap(&a[l],&a[i]);
    }
}
int main()
{ int n;
printf("Enter the number of strings \n");
scanf("%d",&n);
char *ptr[n];
printf("Enter the strings \n");
for(int i=0;i<n;i++)
{   ptr[i]=(char *)calloc(10,sizeof(char));
    scanf("%s",ptr[i]);
}
permute(ptr,0,n-1,n);
for (int i = 0; i < n; i++)
		free(ptr[i]);
	free(ptr);
	return 0;
}