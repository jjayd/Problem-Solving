#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair <int,int> > c; //2
vector<pair <int,int> > h; //1
int cnt; //#of chick

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp==2) c.push_back(pair<int,int> (i,j));
			if(tmp==1) h.push_back(pair<int,int> (i,j));
		}
	}

	

}