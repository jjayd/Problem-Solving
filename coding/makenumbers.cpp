#include <iostream>

using namespace std;

int n;
int tmax,tmin;
int value;
int op[12];
int arr[12];

void dfs(int cnt)
{
	if(cnt==n)
	{
		if(tmax<value) tmax=value;
		if(tmin>value) tmin=value;
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(op[i]>0)
		{
			int tmp=value;
			if(i==0) value+=arr[cnt];
			if(i==1) value-=arr[cnt];
			if(i==2) value*=arr[cnt];
			if(i==3) value/=arr[cnt];
	//		printf("i: %d tmp: %d value: %d\n",i,tmp,value);
			op[i]--;
			dfs(cnt+1);
			value=tmp;
			op[i]++;
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
		tmax=-100000001;
		tmin=100000001;
		for(int i=0;i<4;i++)
			cin>>op[i];

		for(int i=0;i<n;i++)
			cin>>arr[i];

		value=arr[0];

		dfs(1);

		printf("#%d %d\n",p,tmax-tmin);
	}
}