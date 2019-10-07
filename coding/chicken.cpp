#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int cityDist=99999999;
int housDist[101];
int n,m;
int arr[51][51];

vector<pair<int, int> > chic;
vector<pair<int, int> > house;

bool chk[2501];
int k=0;
int start;

void dfs(int cnt,int start)
{
	if(cnt==m)
	{
		for(int i=0;i<house.size();i++)
			housDist[i]=300;
	
		vector<pair<int,int> >::iterator iter;
		int sum=0;
		int countForHouse=0;

		for(iter=house.begin() ; iter!=house.end() ; iter++)
		{
			int tmp;
			int a,b;

			a=iter->first;
			b=iter->second;

			int x,y;
			for(int i=0;i<chic.size();i++)
			{
				if(chk[i]==true)
				{
					x=chic[i].first;
					y=chic[i].second;
					tmp=abs(x-a)+abs(y-b);
					 
					if(tmp<housDist[countForHouse]) housDist[countForHouse] = tmp;

				}
			}
			countForHouse++;
			
		}

		for(int i=0;i<house.size();i++)
			sum+=housDist[i];

		if(sum<cityDist) cityDist=sum;
		return ;
	}

	for(int i=start;i<chic.size();i++)
	{
		if(chk[i]==false)
		{
			chk[i]=true;
			k++;
		
			dfs(cnt+1,i+1);
			
			chk[i]=false;
		}
	}
	
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			pair<int, int> tmp=make_pair(i,j);
			if(arr[i][j]==1) house.push_back(tmp);
			if(arr[i][j]==2) chic.push_back(tmp);

		}
	}


	for(int i=0;i<house.size();i++)
	{
		housDist[i]=300;
	}

	dfs(0,0);

	cout<<cityDist;
}