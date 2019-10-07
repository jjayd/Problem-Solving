#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
using namespace std;

int n,m,k;
vector<pair<pair<int,int>, int> > arr;
long long ans;

int** map;

vector<int> cases(int up, int left, int leup)
{
	vector<int> cur;
	if(up==-1 && left==-1)
	{
		cur.push_back(1);
		cur.push_back(2);
		cur.push_back(3);
		cur.push_back(4);
	}
	else if(up==-1 && left==1)
	{
		cur.push_back(2);
		cur.push_back(3);
	}
	else if(up==-1 && left==2)
	{
		cur.push_back(1);
		cur.push_back(4);
	}
	else if(up==-1 && left==3)
	{
		cur.push_back(1);
		cur.push_back(4);
	}
	else if(up==-1 && left==4)
	{
		cur.push_back(2);
		cur.push_back(3);
	}
	else if(up==1 && left==-1)
	{
		cur.push_back(3);
		cur.push_back(4);
	}
	else if(up==1 && left==1)
	{
		cur.push_back(3);
	}
	else if(up==1 && left==2)
	{
		cur.push_back(4);
	}
	else if(up==1 && left==3)
	{
		cur.push_back(4);
	}
	else if(up==1 && left==4)
	{
		cur.push_back(3);	
	}
	else if(up==2 && left==-1)
	{
		cur.push_back(3);
		cur.push_back(4);
	}
	else if(up==2 && left==1)
	{
		cur.push_back(3);
	}
	else if(up==2 && left==2)
	{
		cur.push_back(4);
	}
	else if(up==2 && left==3)
	{
		cur.push_back(4);
	}
	else if(up==2 && left==4)
	{
		if(leup==1) cur.push_back(-1);
		else cur.push_back(3);
	}
	else if(up==3 && left==-1)
	{
		cur.push_back(1);
		cur.push_back(2);
	}
	else if(up==3 && left==1)
	{
		cur.push_back(2);
	}
	else if(up==3 && left==2)
	{
		cur.push_back(1);
	}
	else if(up==3 && left==3)
	{
		cur.push_back(1);
	}
	else if(up==3 && left==4)
	{
		cur.push_back(2);
	}
	else if(up==4 && left==-1)
	{
		cur.push_back(1);
		cur.push_back(2);
	}
	else if(up==4 && left==1)
	{
		cur.push_back(2);
	}
	else if(up==4 && left==2)
	{
		if(leup==3) cur.push_back(-1);
		else cur.push_back(1);
	}
	else if(up==4 && left==3)
	{
		cur.push_back(1);
	}
	else if(up==4 && left==4)
	{
		cur.push_back(2);
	}

	return cur;
}

int chk(int x, int y, int** map, int dir) // x,y position dir ok?
{
	if(x!=0)
	{
		int tmp = map[x-1][y];
		if(tmp==1 && dir==2) return 0;
		if(tmp==2 && dir==1) return 0;

		if(tmp==3 && dir==4) return 0;
		if(tmp==4 && dir==3) return 0;
	}
	if(y!=0)
	{
		int tmp = map[x][y-1];
		if(tmp==1 && dir==4) return 0;
		if(tmp==4 && dir==1) return 0;

		if(tmp==3 && dir==2) return 0;
		if(tmp==2 && dir==3) return 0;

	}
	return 1;
}

void act(int x, int y, int** map)
{
	int cur = map[x][y];
	int right,under;
	for(int i=0;i<arr.size();i++)
	{
		int tmpx = arr[i].first.first;
		int tmpy = arr[i].first.second;
		if(tmpx==x+1 && tmpy==y)
		{
			printf("exists! dir: %d\n",arr[i].second);
			if(chk(x+1,y,map,arr[i].second))
				map[x+1][y]=arr[i].second;
			else return;
		}
		else if(tmpx==x && tmpy==y+1)
		{
			printf("exists! dir: %d\n",arr[i].second);
			int pos = chk(x,y+1,map,arr[i].second);
			if(chk(x,y+1,map,arr[i].second))
				map[x][y+1]=arr[i].second;
			else return;
		}
	}

	


	if(map[x][y+1]==0)
	{
		int up,leup;
		up=-1;
		leup=-1;
		if(x!=0 && y!=m) up = map[x-1][y];
		if(x!=0) leup=map[x-1][y];
		vector<int> cur = cases(up,cur,leup);
	}

	if(map[x+1][y]==0)
	{
		int left,leup;
		left=-1;
		leup=-1;
		if(x!=0 && y!=m) left = map[x+1][y-1];
		if(y!=0) leup=map[x][y-1];
		vector<int> cur = cases(cur,left,leup);
	}









	printf("(%d, %d)\n",x,y);
	if(x>=n || y>=m) return;
	for(int i=0;i<arr.size();i++)
	{
		int tmpx = arr[i].first.first;
		int tmpy = arr[i].first.second;
		if(tmpx==x && tmpy==y)
		{
			printf("exists! dir: %d\n",arr[i].second);
			int pos = chk(x,y,map,arr[i].second);
			if(pos)
			{
				map[x][y]=arr[i].second;
				act(x+1,y,map);
				act(x,y+1,map);
				return;
			}
			else return;
		}
	}

	int up,left,leup;
	up=-1;
	left=-1;
	leup=-1;
	if(x!=0) up = map[x-1][y];
	if(y!=0) left = map[x][y-1];
	if(x!=0 && y!=0) leup=map[x-1][y-1];
	printf("%d %d %d\n",up,left,leup);
	vector<int> cur = cases(up,left,leup);
	printf("size of cur:%d\n",cur.size());
	if(cur[0]==-1) return;
	for(int i=0;i<cur.size();i++)
	{
		printf("\t(%d, %d): %d\n",x,y,cur[i]);
		map[x][y]=cur[i];
		if(x == n-1 && y == m-1)
		{
			ans++;
			continue;
		}
		act(x+1,y,map);
		act(x,y+1,map);
	}
	
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>k;
		arr.clear();
		ans=0;
		map = new int*[n];
		for(int j=0;j<n;j++)
		{
			map[j]=new int[m];
			for(int k=0;k<m;k++)
				map[j][k]=0;
		}
		int exc=-1;
		for(int j=0;j<k;j++)
		{
			int tmpx, tmpy, tmp;
			cin>>tmpx>>tmpy>>tmp;
			if(tmpx==1 && tmpy==1) exc=tmp;
			arr.push_back(make_pair(make_pair(tmpx-1,tmpy-1),tmp));
		}
		if(exc!=-1)
		{
			map[0][0]=exc;
			act(0,0,map);
		}
		else
		{
			map[0][0]=1;
			act(0,0,map);
			map[0][0]=2;
			act(0,0,map);
			map[0][0]=3;
			act(0,0,map);
			map[0][0]=4;
			act(0,0,map);
		}
		act(0,0,map);
		printf("#%d %lld\n",i,ans);
	
	}
}

