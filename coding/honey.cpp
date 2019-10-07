#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

int n,m,c;
int arr[10][10];
int tmax;
int ax,ay,bx,by;
vector<int> worker;
int flag[10][10];

vector<int> w[2];

int chk[5];
int wmax;

int cal(int x)
{
	int tmp=0;
	int tmpresult=0;
	for(int i=0;i<w[x].size();i++)
	{
		if(chk[i]==1)
		{
			tmp+=w[x][i];
			tmpresult+=w[x][i]*w[x][i];
		}
	}
	
	if(tmp>c) return 0;
	else return tmpresult;

}

void wdfs(int x, int ptr)
{
	int tmp = cal(x);
	if(wmax<tmp) wmax=tmp;

	for(int i=ptr;i<w[x].size();i++)
	{
		chk[i]=1;
		wdfs(x,i+1);
		chk[i]=0;

	}
}

int solve()
{
	ax=worker[0]/n;
	ay=worker[0]%n;
	bx=worker[1]/n;
	by=worker[1]%n;

	if(ax==bx && abs(ay-by)<c) return 0;

	w[0].clear();
	w[1].clear();

	
	int amax,bmax;
	for(int i=0;i<m;i++)
	{
		if(ay+i<n) w[0].push_back(arr[ax][ay+i]);
		if(by+i<n) w[1].push_back(arr[bx][by+i]);
	}

	for(int i=0;i<5;i++) chk[i]=0;
	wmax=0;
	wdfs(0,0);
	amax=wmax;
	for(int i=0;i<5;i++) chk[i]=0;
	wmax=0;
	wdfs(1,0);
	bmax=wmax;

	
	return amax+bmax;
		
	
}

void dfs(int cnt, int ptr)
{
	if(cnt==2)
	{
		int tmp=solve();
		if(tmp>tmax) tmax=tmp;
		return;
	}
	for(int i=ptr;i<n*n;i++)
	{
		worker.push_back(i);
		dfs(cnt+1,ptr+1);
		worker.pop_back();
	}
}

int main()
{
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		tmax=0;
		cin>>n>>m>>c;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				flag[i][j]=0;
				cin>>arr[i][j];
			}
		}

		dfs(0,0);

		printf("#%d %d\n",p,tmax);
	}
}