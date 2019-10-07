#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void bfs(int start, vector<int> graph[], bool check[])
{
	queue<int> q;
	q.push(start);
	check[start]=true;

	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		printf("%d ",cur);

		for(int i=0;i<graph[cur].size();i++)
		{
			if(check[graph[cur][i]]==false)
			{
				q.push(graph[cur][i]);
				check[graph[cur][i]]=true;
			}
		}
	}

}

void dfs(int start, vector<int> graph[], bool check[])
{
	stack<int> s;
	s.push(start);
	check[start]=true;
	printf("%d ",start);

	while(!s.empty())
	{
		int cur = s.top();
		s.pop();
		for(int i=0;i<graph[cur].size();i++)
		{
			int next=graph[cur][i];
			if(check[next]==false)
			{
				printf("%d ",next);
				check[next]=true;
				s.push(cur);
				s.push(next);
				break;
			}
		}
	}
}

void dfs_recur(int start, vector<int> graph[], bool check[])
{
	check[start]=true;
	printf("%d ",start);

	for(int i=0;i<graph[start].size();i++)
	{
		int next=graph[start][i];
		if(check[next]==false)
			dfs_recur(next,graph,check);
	}
}



int main()
{

	int n,m,start;
	cin>>n>>m>>start;
	vector<int> graph[n+1];
	bool check[n+1];
	

	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;

		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	for(int i=1; i<=n;i++)
		sort(graph[i].begin(),graph[i].end());

	fill(check,check+n+1,false);
	dfs(start,graph,check);
	printf("\n");

	fill(check,check+n+1,false);
	//dfs_recur(start,graph,check);
	//printf("\n");

	fill(check,check+n+1,false);
	bfs(start,graph,check);
	printf("\n");

}
