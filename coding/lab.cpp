#include <iostream>

using namespace std;

int arr[10][10];
int tmparr[10][10];
int n,m;
int tmax=0;

void savemap()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			tmparr[i][j]=arr[i][j];
	}
}

void remap()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			arr[i][j]=tmparr[i][j];
		
	}
}

void spread(int x,int y)
{
	if(x-1>=0 && arr[x-1][y]==0)
	{
		arr[x-1][y]=2;
		spread(x-1,y);
	}
	if(y-1>=0 && arr[x][y-1]==0)
	{
		arr[x][y-1]=2;
		spread(x,y-1);
	}
	if(x+1<n && arr[x+1][y]==0)
	{
		arr[x+1][y]=2;
		spread(x+1,y);
	}
	if(y+1<m && arr[x][y+1]==0)
	{
		arr[x][y+1]=2;
		spread(x,y+1);
	}
}

int cal()
{
	int safe=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==2)
			{
				spread(i,j);
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==0)
				safe++;
		}
	}

	return safe;
}

int cases=0;

void dfs(int ptr, int cnt)
{
	if(cnt==3)
	{
		cases++;
		savemap();
		int tmp=cal();
		if(tmp>tmax)
			tmax=tmp;
		remap();
		return;
	}

	for(int k=ptr;k<n*m;k++)
	{
		int i=k/m;
		int j=k%m;

		if(arr[i][j]==0)
		{
			arr[i][j]=3;
			dfs(ptr+1,cnt+1);
			arr[i][j]=0;
		}
	}
}


int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	}

	dfs(0,0);

	cout<<tmax;
}