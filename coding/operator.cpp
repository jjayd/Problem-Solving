#include <iostream>
#include <algorithm>

using namespace std;

int n;
int op[4];
int arr[105];
int tmax=-1000000000;
int tmin=1000000000;
int val=0;

void dfs(int cnt, int val)
{
	if(cnt==n-1)
	{
		if(val>tmax) tmax=val;
		if(val<tmin) tmin=val;
		return;
	}

	for(int j=0;j<4;j++)
	{
		if(op[j]>0)
		{
			int tmp=val;
			if(j==0) val+=arr[cnt+1];
			if(j==1) val-=arr[cnt+1];
			if(j==2) val*=arr[cnt+1];
			if(j==3) val/=arr[cnt+1];

			op[j]--;
			dfs(cnt+1,val);
		
			val = tmp;
			op[j]++;

		}
	}
	
}


int main()
{
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		cin>>n;
		tmax=-1000000000;
		tmin=1000000000;
		
		cin>>op[0]>>op[1]>>op[2]>>op[3];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		val=arr[0];

		dfs(0,val);

		printf("#%d %d\n",p,tmax-tmin);
	}
	

}