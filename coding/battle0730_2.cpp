#include <iostream>
#include <vector>

using namespace std;

int arr[3000001];

int main()
{
	int T,t,i;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		int n;
		int tmp;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>tmp;
			arr[tmp-1]=i;
		}
		int cnt=0;
		for(i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
				cnt++;
		}
		printf("#%d %d\n",t,cnt+1);
	}
}