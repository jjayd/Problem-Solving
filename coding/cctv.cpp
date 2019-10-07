#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,m;
int ncctv;
int arr[10][10];
int savearr[10][10];
int tmax=999999999;
int dir[10];

vector<pair<int,int> > cctv;

void savemap()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			savearr[i][j]=arr[i][j];
	}
}

void unmap()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			arr[i][j]=savearr[i][j];
	}
}

void ways(int x,int y, int way)
{
	if(way==0)
	{
		for(int i=1;i<n;i++)
		{
			if(x-i>=0)
			{
				if(arr[x-i][y]==6) break;
				else if(arr[x-i][y] ==0) arr[x-i][y]=8;
			}
		}
	}
	else if(way==1)
	{
		for(int i=1;i<m;i++)
		{
			if(y+i<m)
			{
				if(arr[x][y+i]==6) break;
				else if(arr[x][y+i] ==0) arr[x][y+i]=8;
			}
		}

	}
	else if(way==2)
	{
		for(int i=1;i<n;i++)
		{
			if(x+i<n)
			{
				if(arr[x+i][y]==6) break;
				else if(arr[x+i][y] ==0) arr[x+i][y]=8;
			}
		}
	}
	else
	{
		for(int i=1;i<m;i++)
		{
			if(y-i>=0)
			{
				if(arr[x][y-i]==6) break;
				else if(arr[x][y-i] ==0) arr[x][y-i]=8;
			}
		}
	}
}

int cal()
{
	for(int k=0;k<ncctv;k++)
	{
		int x = cctv[k].first;
		int y = cctv[k].second;
		int way=dir[k];

		if(arr[x][y]==1) ///////////////////////////////////////////////////////
		{
			ways(x,y,way);
		}
		else if(arr[x][y]==2) /////////////////////////////////////////////////
		{
			if(way==13)
			{
				ways(x,y,1);
				ways(x,y,3);
			}
			else if(way==20)
			{
				ways(x,y,0);
				ways(x,y,2);
			}
		}
		else if(arr[x][y]==3) /////////////////////////////////////////////////////
		{
			if(way==10)
			{
				ways(x,y,0);
				ways(x,y,1);
			}
			else if(way==21)
			{
				ways(x,y,1);
				ways(x,y,2);
			}
			else if(way==32)
			{
				ways(x,y,3);
				ways(x,y,2);
			}
			else
			{
				ways(x,y,0);
				ways(x,y,3);
			}
		}
		else if(arr[x][y]==4) ///////////////////////////////////////////////////////
		{
			if(way==0)
			{
				ways(x,y,1);
				ways(x,y,2);
				ways(x,y,3);
			}
			else if(way==1)
			{
				ways(x,y,0);
				ways(x,y,2);
				ways(x,y,3);
			}
			else if(way==2)
			{
				ways(x,y,1);
				ways(x,y,0);
				ways(x,y,3);
			}
			else
			{
				ways(x,y,1);
				ways(x,y,2);
				ways(x,y,0);
			}
		}
		else if(arr[x][y]==5) ////////////////////////////////////////////////////////
		{
			ways(x,y,0);
			ways(x,y,1);
			ways(x,y,2);
			ways(x,y,3);
		}

	}

	int tmp=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==0) tmp++;
		}
	}

	return tmp;
}

void dfs(int cnt)
{
	if(cnt==ncctv)
	{	
		savemap();
		int tmp=cal();
		unmap();
		if(tmp<tmax) tmax=tmp;
		return;
	}

	for(int i=cnt;i<ncctv;i++)
	{
		int x=cctv[i].first;
		int y=cctv[i].second;

		cnt++;

		if(arr[x][y]==1)
		{
			dir[i]=0;
			dfs(cnt);
			dir[i]=1;
			dfs(cnt);
			dir[i]=2;
			dfs(cnt);
			dir[i]=3;
			dfs(cnt);
		}
		else if(arr[x][y]==2)
		{
			dir[i]=13;
			dfs(cnt);
			dir[i]=20;
			dfs(cnt);
		}
		else if(arr[x][y]==3)
		{
			dir[i]=10;
			dfs(cnt);
			dir[i]=21;
			dfs(cnt);
			dir[i]=32;
			dfs(cnt);
			dir[i]=30;
			dfs(cnt);
		}
		else if(arr[x][y]==4)
		{
			dir[i]=0;
			dfs(cnt);
			dir[i]=1;
			dfs(cnt);
			dir[i]=2;
			dfs(cnt);
			dir[i]=3;
			dfs(cnt);
		}
		else if(arr[x][y]==5)
		{
			dfs(cnt);
		}
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
			if(arr[i][j]>=1 && arr[i][j] <=5)
			{
				ncctv++;
				cctv.push_back(make_pair(i,j));
			}
		}
	}

	dfs(0);

	cout<<tmax;
}