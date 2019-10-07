#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
int chk[101];
int tmax;
int dx[4]={-1,1,1,-1};
int dy[4]={1,1,-1,-1};


int cal(int x, int y, int a, int b) // 시작위치, 길이 
{
	int tmp_max=0;
	int length;
	for(int p=0;p<4;p++)
	{
		if(x+a*dx[p] >= n || x + a*dx[p] <0 || y+a*dy[p] >=n || y+a*dy[p] <0) continue;
		if(x+a*dx[p]+b*dx[(p+1)%4] >= n || x + a*dx[p]+b*dx[(p+1)%4] <0 || y+a*dy[p]+b*dy[(p+1)%4] >=n || y+a*dy[p]+b*dy[(p+1)%4] <0) continue;
		if(x+a*dx[p]+b*dx[(p+1)%4]+a*dx[(p+2)%4]>= n || x + a*dx[p]+b*dx[(p+1)%4]+a*dx[(p+2)%4] <0 || y+a*dy[p]+b*dy[(p+1)%4]+a*dy[(p+2)%4] >=n || y+a*dy[p]+b*dy[(p+1)%4]+a*dy[(p+2)%4] <0) continue;
		
		vector<int> go;
		int tmpx = x;
		int tmpy = y;

		for(int q=0;q<4;q++)
		{
			if(q%2==0) length=a;
			else length=b;
			for(int i=1;i<=length;i++)
			{
				tmpx += dx[(p+q)%4];
				tmpy += dy[(p+q)%4];

				go.push_back(arr[tmpx][tmpy]);
			}
			
		}
		int size=go.size();

		
		sort(go.begin(),go.end());
		go.erase(unique(go.begin(),go.end()),go.end());
		
		if(go.size()==size && tmp_max<size) tmp_max=size;
	}

	return tmp_max;
}
//1~n-1
void solve()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int x=1;x<n;x++)
			{
				for(int y=1;y<n;y++)
				{
					int tmp = cal(i,j,x,y);
					if(tmax<tmp) tmax=tmp;
				}
			}
			
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
		tmax=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		}

		solve();
		if(tmax==0) tmax=-1;
		printf("#%d %d\n",p,tmax);
	}
}
