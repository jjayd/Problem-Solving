#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

char arr[11][11];
int n,m;

int rx,ry,bx,by,hx,hy;
int chk=0;

vector<pair<int, pair<pair<int, int>, pair<int,int> >> > v; 

int roll(int dir)
{
	int chk=0;
	int zrx,zry,zbx,zby;
	int cnt = v[0].first;

	zrx=rx;
	zry=ry;
	zbx=bx;
	zby=by;

	if(dir==0) //up
	{
		for(int i=rx-1;i>=0;i--) 
		{
			if(arr[i][ry]=='O') chk=5;
			else if(arr[i][ry]=='.') zrx=i; 
			else break;
		}

		for(int i=bx-1;i>=0;i--)
		{
			if(arr[i][by]=='O') chk++;
			else if(arr[i][by]=='.') zbx=i;
			else break;
		}
		if(chk==6) return 2;
		else if(chk==1) return 2;
		else if(chk==5) return 1;

		if(zry==zby && zrx==zbx)
		{
			if(rx<bx) zbx++;
			else if(rx>bx) zrx++;
		}
	}
	else if(dir==1) //right
	{
		for(int i=ry+1;i<m;i++) 
		{
			if(arr[rx][i]=='O') chk=5;
			else if(arr[rx][i]=='.') zry=i; 
			else break;
		}

		for(int i=by+1;i<m;i++)
		{
			if(arr[bx][i]=='O') chk++;
			else if(arr[bx][i]=='.') zby=i;
			else break;
		}
		if(chk==6) return 2;
		else if(chk==1) return 2;
		else if(chk==5) return 1;

		if(zrx==zbx && zry==zby)
		{
			if(ry<by) zry--;
			else if(ry>by) zby--;
		}

	}
	else if(dir==2) //down
	{
		for(int i=rx+1;i<n;i++) 
		{
			if(arr[i][ry]=='O') chk=5;
			else if(arr[i][ry]=='.') zrx=i; 
			else break;
		}

		for(int i=bx+1;i<n;i++)
		{
			if(arr[i][by]=='O') chk++;
			else if(arr[i][by]=='.') zbx=i;
			else break;
		}
		if(chk==6) return 2;
		else if(chk==1) return 2;
		else if(chk==5) return 1;

		if(zry==zby && zrx==zbx)
		{
			if(rx<bx) zrx--;
			else if(rx>bx) zbx--;
		}
	}
	else //left
	{
		for(int i=ry-1;i>=0;i--) 
		{
			if(arr[rx][i]=='O') chk=5;
			else if(arr[rx][i]=='.') zry=i; 
			else break;
		}

		for(int i=by-1;i>=0;i--)
		{
			if(arr[bx][i]=='O') chk++;
			else if(arr[bx][i]=='.') zby=i;
			else break;
		}
		if(chk==6) return 2;
		else if(chk==1) return 2;
		else if(chk==5) return 1;

		if(zrx==zbx && zry==zby)
		{
			if(ry<by) zby++;
			else if(ry>by) zry++;
		}
	}

	v.push_back(make_pair(cnt+1,make_pair(make_pair(zrx,zry),make_pair(zbx,zby))));
	
	return 0;
}

void bfs()
{
	while(!v.empty())
	{	
		if(v[0].first==10)
		{
			cout<<"-1";
			return;
		}

		rx = v[0].second.first.first;
		ry = v[0].second.first.second;
		bx = v[0].second.second.first;
		by = v[0].second.second.second;

		for(int i=0;i<4;i++)
		{
			chk = roll(i);
			if(chk==1)
			{
				cout<<v[0].first+1;
				return;
			}
		}
		v.erase(v.begin());
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		
			
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]=='R')
			{
				rx=i;
				ry=j;
				arr[i][j]='.';
			}
			else if(arr[i][j]=='B')
			{
				bx=i;
				by=j;
				arr[i][j]='.';
			}
			else if(arr[i][j]=='O')
			{
				hx=i;
				hy=j;
			}
		}
	}

	v.push_back(make_pair(0,make_pair(make_pair(rx,ry),make_pair(bx,by))));

	bfs();
}