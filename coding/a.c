#include <stdio.h>
#include <iostream>
using namespace std;

int g[4001][4001];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		g[a][b]=w;
		g[b][a]=w;
	}
	
}