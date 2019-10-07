//11시 시작 

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int arr[20][20];
int chk[20];
int n;

int tmin;

int solve(int chk[20])
{
	vector<int> a;
	vector<int> b;

//	for(int i=0;i<n;i++) printf("%d ",chk[i]);
//	printf("\n");

	for(int i=0;i<n;i++)
	{
		if(chk[i]==0)
			a.push_back(i);
		else
			b.push_back(i);
	}

	int first=0;
	int second=0;

	for(int i=0;i<n/2-1;i++)
	{
		for(int j=i+1;j<n/2;j++)
		{
			int ax=a[i];
			int ay=a[j];
			int bx=b[i];
			int by=b[j];
			first+=arr[ax][ay];
			first+=arr[ay][ax];
			second+=arr[bx][by];
			second+=arr[by][bx];
		}
	}

	return abs(first-second);
}

void dfs(int cnt, int chk[20], int ptr)
{
	if(cnt==n/2)
	{
		int tmp=solve(chk);
		if(tmp<tmin) tmin=tmp;
		return;
	}

	for(int i=ptr;i<n;i++)
	{
		chk[i]=1;
		dfs(cnt+1,chk,i+1);
		chk[i]=0;
	}

}


int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		tmin=99999999;
		cin>>n;
		for(int i=0;i<n;i++) chk[i]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		}
		dfs(0,chk,0);
		printf("#%d %d\n",k,tmin);
	}
}