#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

int m,a;
//int map[11][11];
int arr1[100]; // a:3
int arr2[100]; // b:6
int tmax;
int ax,ay,bx,by;

//vector<pair<int,int> > bc;
vector<pair<int,int> > map[11][11];

void solve()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			sort(map[i][j].begin(),map[i][j].end());
			reverse(map[i][j].begin(),map[i][j].end());
		}
	}



	for(int i=-1;i<m;i++)
	{
	//	printf("\ti: %d ",i);

	//	printf("(%d %d) (%d %d)\n",ax,ay,bx,by);

	//	printf("to %d %d\n",arr1[i],arr2[i]);
		
		if(i>=0)
		{
			if(arr1[i]==1) ax--;
			else if(arr1[i]==2) ay++;
			else if(arr1[i]==3) ax++;
			else if(arr1[i]==4) ay--; 

			if(arr2[i]==1) bx--;
			else if(arr2[i]==2) by++;
			else if(arr2[i]==3) bx++;
			else if(arr2[i]==4) by--; 
		}

	//	printf("(%d %d) (%d %d)\n",ax,ay,bx,by);

		if(map[ax][ay].size()==1 && map[bx][by].size()==1 && map[ax][ay][0].second==map[bx][by][0].second)
		{
			tmax+=map[ax][ay][0].first;
//			printf("same!\n");
			continue;
		}

		if(map[ax][ay].size()==0 && map[bx][by].size()==0)
		{
//			printf("%d\n",0);
			continue;
		} 
		else if(map[ax][ay].size()==0)
		{
			tmax+=map[bx][by][0].first;
//			printf("%d\n",map[bx][by][0].first);
			continue;
		}
		else if(map[bx][by].size()==0)
		{
			tmax+=map[ax][ay][0].first;
//			printf("%d\n",map[ax][ay][0].first);
			continue;
		}

		if(map[ax][ay][0].second==map[bx][by][0].second)
		{
			if(map[ax][ay].size()==1)
			{
				tmax+=map[ax][ay][0].first;
				tmax+=map[bx][by][1].first;
//				printf("%d %d\n",map[ax][ay][0].first,map[bx][by][1].first);
			}
			else if(map[bx][by].size()==1)
			{
				tmax+=map[ax][ay][1].first;
				tmax+=map[bx][by][0].first;
//				printf("%d %d\n",map[ax][ay][1].first,map[bx][by][0].first);
			}
			else
			{
				if(map[ax][ay][1].first > map[bx][by][1].first)
				{
					tmax+=map[ax][ay][1].first;
					tmax+=map[bx][by][0].first;
//					printf("%d %d\n",map[ax][ay][1].first,map[bx][by][0].first);
				}
				else
				{
					tmax+=map[ax][ay][0].first;
					tmax+=map[bx][by][1].first;
//					printf("%d %d\n",map[ax][ay][0].first,map[bx][by][1].first);
				}
			}
		}
		else
		{
			tmax+=map[ax][ay][0].first;
			tmax+=map[bx][by][0].first;
//			printf("%d %d\n",map[ax][ay][0].first,map[bx][by][0].first);
		}
		
	}
}

void make(int x, int y, int size, int p, int num)
{	
//	printf("(%d %d), size: %d num:%d\n",x,y,size,num);
	map[x][y].push_back(make_pair(p,num));

	for(int i=1;i<=size;i++)
	{
		if(x+i<=10) map[x+i][y].push_back(make_pair(p,num));
		if(y+i<=10) map[x][y+i].push_back(make_pair(p,num));
		if(x-i>=1) map[x-i][y].push_back(make_pair(p,num));
		if(y-i>=1) map[x][y-i].push_back(make_pair(p,num));
	}

	if(size>=2)
	{
		if(x+1<=10 && y-1>=1) map[x+1][y-1].push_back(make_pair(p,num));
		if(x+1<=10 && y+1<=10) map[x+1][y+1].push_back(make_pair(p,num));
		if(x-1>=1 && y-1>=1) map[x-1][y-1].push_back(make_pair(p,num));
		if(x-1>=1 && y+1<=10) map[x-1][y+1].push_back(make_pair(p,num));
	}
	if(size>=3)
	{
		if(x+2<=10 && y-1>=1) map[x+2][y-1].push_back(make_pair(p,num));
		if(x+2<=10 && y+1<=10) map[x+2][y+1].push_back(make_pair(p,num));

		if(x-2>=1 && y-1>=1) map[x-2][y-1].push_back(make_pair(p,num));
		if(x-2>=1 && y+1<=10) map[x-2][y+1].push_back(make_pair(p,num));

		if(x+1<=10 && y-2>=1) map[x+1][y-2].push_back(make_pair(p,num));
		if(x+1<=10 && y+2<=10) map[x+1][y+2].push_back(make_pair(p,num));

		if(x-1>=1 && y-2>=1) map[x-1][y-2].push_back(make_pair(p,num));
		if(x-1>=1 && y+2<=10) map[x-1][y+2].push_back(make_pair(p,num));
	}
	if(size>=4)
	{
		if(x+1<=10 && y+3<=10) map[x+1][y+3].push_back(make_pair(p,num));
		if(x+2<=10 && y+2<=10) map[x+2][y+2].push_back(make_pair(p,num));
		if(x+3<=10 && y+1<=10) map[x+3][y+1].push_back(make_pair(p,num));

		if(x+1<=10 && y-3>=1) map[x+1][y-3].push_back(make_pair(p,num));
		if(x+2<=10 && y-2>=1) map[x+2][y-2].push_back(make_pair(p,num));
		if(x+3<=10 && y-1>=1) map[x+3][y-1].push_back(make_pair(p,num));

		if(x-1>=1 && y+3<=10) map[x-1][y+3].push_back(make_pair(p,num));
		if(x-2>=1 && y+2<=10) map[x-2][y+2].push_back(make_pair(p,num));
		if(x-3>=1 && y+1<=10) map[x-3][y+1].push_back(make_pair(p,num));

		if(x-1>=1 && y-3>=1) map[x-1][y-3].push_back(make_pair(p,num));
		if(x-2>=1 && y-2>=1) map[x-2][y-2].push_back(make_pair(p,num));
		if(x-3>=1 && y-1>=1) map[x-3][y-1].push_back(make_pair(p,num));
	}
	
}

void printing()
{
	for(int i=1;i<11;i++)
	{
		for(int j=1;j<11;j++)
		{
			if(map[i][j].size()>0)
				printf("(%d %d): %d\n",i,j,map[i][j].size());
		//	for(int k=0;k<map[i][j].size();k++)

			//	printf("%d's %d\n",map[i][j][k].second, map[i][j][k].first);
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		for(int i=1;i<11;i++)
		{
			for(int j=1;j<11;j++)
				map[i][j].clear();
		}

		tmax=0;
		cin>>m>>a;
		for(int i=0;i<m;i++) cin>>arr1[i];
		for(int i=0;i<m;i++) cin>>arr2[i];
		for(int i=0;i<a;i++)
		{
			int x,y,size,p;
			cin>>y>>x>>size>>p;
			make(x,y,size,p,i);
		}

	//	printing();

		ax=1;
		ay=1;
		bx=10;
		by=10;

		solve();

		printf("#%d %d\n",k,tmax);
		
	}
}