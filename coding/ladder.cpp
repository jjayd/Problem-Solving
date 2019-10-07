#include <iostream>

using namespace std;

int arr[31][31];
int n,m,h;
bool stop=false;

int godown() //return the arrival number
{
	for(int j=1;j<=n;j++)
	{
		int x=j;
		for(int i=1;i<=h;i++)
		{
			if(arr[i][x]==1)
				x++;
			else if(arr[i][x-1]==1)
				x--;
		}
		if(x!=j) return 0;
	}
	return 1;
}

void dfs( int start, int depth, int target_depth)
{
	if(depth > target_depth) return;
	if(depth == target_depth)
	{
		if(godown())
		{
			cout<<depth;
			stop=true;
			return;
		}
	}
	for(int i=start;i<=h;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			if(arr[i][j]==0)
			{
				arr[i][j]=1;
				dfs(i,depth+1,target_depth);
				arr[i][j]=0;
			}
		}
	}
}

int main()
{
	int result;
	cin>>n>>m>>h;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		arr[a][b]=1;
	}
	
	if(godown())
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	for(int i=1;i<=3;i++)
	{
		dfs(1,0,i);
		if(stop==true) return 0;
	}

	cout<<"-1";
	return 0;
}