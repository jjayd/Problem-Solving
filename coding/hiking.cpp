#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
int arr[8][8];
vector<pair<int,pair<int,int> > > findhigh;
vector<pair<int,pair<int,int> > > high;
int dir_x[4]={1,0,-1,0};
int dir_y[4]={0,1,0,-1};
int tmax;


void dfs(int x, int y, int cnt, int flg[8][8], int height, bool shave)
{
	int yes=0;

	//printf("(%d %d) cnt: %d  height: %d shave: %d \n",x,y,cnt,height,shave);
	flg[x][y]=1;

	for(int p=0;p<4;p++)
	{
		int tmpx = x+dir_x[p];
		int tmpy = y+dir_y[p];

		if(tmpx<n && tmpx>=0 && tmpy<n && tmpy>=0 && flg[tmpx][tmpy]==0)
		{
			if(arr[tmpx][tmpy] < height) 
			{
				flg[tmpx][tmpy]=1;
				dfs(tmpx,tmpy,cnt+1,flg,arr[tmpx][tmpy],shave);
				flg[tmpx][tmpy]=0;

				yes=1;
			}
			
			if(!shave && (arr[tmpx][tmpy] - k < height) )
			{
				shave = true;

				flg[tmpx][tmpy]=1;
				for(int i=1;i<=k;i++)
				{
					if(arr[tmpx][tmpy] - i< height)
						dfs(tmpx,tmpy,cnt+1,flg,arr[tmpx][tmpy] - i,shave);
				}
				
				flg[tmpx][tmpy]=0;

				shave = false;

				yes=1;		
			}	
		}
	}

	if(yes==0)
	{
		if(cnt>tmax) tmax=cnt;
		return;
	}


}

void solve()
{
	sort(findhigh.begin(),findhigh.end());
	reverse(findhigh.begin(),findhigh.end());

	high.push_back(findhigh[0]);

	for(int i=1;i<findhigh.size();i++)
	{
		if(findhigh[i].first==findhigh[0].first) high.push_back(findhigh[i]);
		else break;
	}

	int flg[8][8];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			flg[i][j]=0;
	}
	
	bool shave = false;

	for(int i=0;i<high.size();i++)
		printf("%d ",high[i].first);
	printf("\n");

	for(int i=0;i<high.size();i++)
		dfs(high[i].second.first,high[i].second.second,1,flg,high[i].first,shave);

}

int main()
{
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		findhigh.clear();
		high.clear();
		tmax=0;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
				findhigh.push_back(make_pair(arr[i][j],make_pair(i,j)));
			}
		}

		solve();

		printf("#%d %d\n",p,tmax);
	}
}