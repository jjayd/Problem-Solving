//11시 40 분 시작

#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[15][15];
int tmin;
int chk[10];
int stair1[1000];
int stair2[1000];


vector<pair<int, int> > stair;
vector<pair<int, int> > people;

int cal(int q, int a, int b)
{
	if(q==0) return abs(a-stair[0].first)+abs(b-stair[0].second);
	else return abs(a-stair[1].first)+abs(b-stair[1].second);
}

int solve(int chk[20])
{
	int time1=0;
	int time2=0;
	vector<int> s1;
	vector<int> s2;

	for(int i=0;i<people.size();i++)
	{
		if(chk[i]==0) s1.push_back(cal(0,people[i].first,people[i].second));
		else s2.push_back(cal(1,people[i].first,people[i].second));
	}

	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());

	int size1=s1.size();
	int size2=s2.size();

	for(int i=0;i<1000;i++) stair1[i]=0;
	for(int i=0;i<1000;i++) stair2[i]=0;

	for(int i=0;i<size1;i++)
	{
		int S=s1[i];
		S++;

		while(1)
		{
			if(stair1[S]>=3) S++;
			else break;
		}

		for(int j=0;j<arr[stair[0].first][stair[0].second];j++)
		{
			stair1[S+j]++;
		}
		
	}
	for(int i=999;i>=0;i--)
	{
		if(stair1[i]!=0)
		{
			time1=i;
			break;
		}
	}

	for(int i=0;i<size2;i++)
	{
		int S=s2[i];
		S++;

		while(1)
		{
			if(stair2[S]>=3) S++;
			else break;
		}

		for(int j=0;j<arr[stair[1].first][stair[1].second];j++)
		{
			stair2[S+j]++;
		}
		
	}

	for(int i=999;i>=0;i--)
	{
		if(stair2[i]!=0)
		{
			time2=i;
			break;
		}
	}

	return max(time1,time2);
}

void dfs(int cnt, int ptr, int chk[10])
{
	//printf("cnt:%d\n",cnt);
	if(cnt==people.size())
	{
		int tmp=solve(chk);
		if(tmp<tmin) tmin=tmp;
		return;
	}

	for(int i=ptr ; i<people.size() ; i++)
	{
		chk[i]=0;
		dfs(cnt+1,i+1,chk);
		chk[i]=1;
		dfs(cnt+1,i+1,chk);
	}
}

int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		tmin=99999999;
		stair.clear();
		people.clear();
		for(int i=0;i<10;i++) chk[i]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j]>1) stair.push_back(make_pair(i,j));
				else if(arr[i][j]==1) people.push_back(make_pair(i,j));
			}
		}

		dfs(0,0,chk);
		printf("#%d %d\n",k,tmin+1);

	}
}