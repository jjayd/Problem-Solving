#include <iostream>

using namespace std;

int arr[10];
int cnt;

void swap(int a,int b)
{
 	int tmp=arr[a];
    arr[a]=arr[b];
    arr[b]=tmp;
}

void findMax(int start, int end)
{
    int max=0;
    int index;
	for(int i=start;i<=end;i++)
    {
     	   if(arr[i]>max)
           {
			   max=arr[i];
               index=i;
           }
    }
    
    if(max>arr[end+1]) 
    {
    	cnt--;
    	swap(index,end+1);
    }
    else
        findMax(start,end-1);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int input;
        int len=0;
		scanf("%d %d",&input,&cnt);
		int j=0;
		while(input!=0)
		{
			arr[j]=input%10;
			input=input/10;
            len++;
            j++;
		}

        for(int j=1;j<=cnt;j++)
        {
         	findMax(0,len-j-1);   
        }
        printf("#%d ",i+1);
        for(int j=len-1;j>=0;j--)
            printf("%d",arr[j]);
        printf("\n");
	}
}