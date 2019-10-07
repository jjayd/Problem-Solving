#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int arr[20][20];

int n,m;
int tmax;
int operate[25];

vector<pair<int, int> > home;

int cal(int x, int y, int size)
{
	int cnt=0;

//	printf("(%d %d) size: %d ", x,y,size);

	for(int i=0;i<home.size();i++)
	{
		int tmpx = home[i].first;
		int tmpy = home[i].second;

		int dist = abs(tmpx-x)+abs(tmpy-y);

		if(dist<size) cnt++;
	}

//	printf("profit: %d operate: %d\n",cnt*m,operate[size]);
	if(cnt*m - operate[size] >=0) return cnt;

	return 0;
}

void solve()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=1;k<n+5;k++)
			{
				int tmp=cal(i,j,k);
				if(tmax<tmp) tmax=tmp;
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<25;i++)
		operate[i]=i*i+(i-1)*(i-1);
	for(int p=1;p<=t;p++)
	{
		home.clear();
		tmax=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];

				if(arr[i][j]==1)
					home.push_back(make_pair(i,j));
			}
		}

	//	printf("home num:%d\n",home.size());

		solve();

		printf("#%d %d\n",p,tmax);
	}
}