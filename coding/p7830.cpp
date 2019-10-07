#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n,m;
int arr[750][750];
int mmax;
int dirx[4]={1,1,-1,-1};
int diry[4]={-1,1,1,-1};

pair<int,int> p;
vector<pair<int,int> > v;

int most(int x,int y)
{
	vector<int> tmp;
	tmp.push_back(x);
	tmp.push_back(y);
	tmp.push_back(m-y-1);
	tmp.push_back(n-x-1);
	sort(tmp.begin(),tmp.end());
	return tmp[0];
}

bool chk(int x, int y)
{
	if(arr[x][y]==0) return true; // if not possible
	else return false; // if possible
}

int find(int x, int y)
{
	int len=most(x,y);
	printf("(%d %d): %d\n",x,y,len);

	int i;

	for(i=len;i>mmax;i--)
	{
		int curx = x-i;
		int cury = y;
		int pos=1;

		for(int dir=0;dir<4;dir++)
		{
			for(int j=0;j<i;j++)
			{
				curx = curx + dirx[dir];
				cury = cury + diry[dir];

				if(chk(curx, cury))
				{
					pos=0;
					goto a;
				}

			}
		}
	a:
		if(pos) break;

	}


	return i;
}

int main()
{
	int T;
	cin>>T;
	int chk;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m;
		mmax=0;
		chk=0;
		v.clear();
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			for(int k=0;k<m;k++)
			{
				arr[j][k] = tmp%10;
				if(arr[j][k]==1) chk=1;
				tmp=tmp/10;
			}
		}
		
		if(chk==0) 
		{
			printf("#%d 0\n",i);
			continue;
		}
		if(n==1 || m==1) 
		{
			printf("#%d 1\n",i);
			continue;
		}

		int tmp;
		
		for(int j=1;j<n-1;j++)
		{
			for(int k=1;k<m-1;k++)
			{
				tmp=find(j,k);
				if(tmp>mmax) mmax=tmp;
			}
		}

		printf("#%d %d\n",i,mmax+1);
	}
}