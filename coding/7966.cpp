#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n; // num of p
vector<int> price;
vector<int> bt;
int x;
int k;
vector<int> have;
int mon;
int ans;

void go()
{

}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		int tmp;
		mon=0;
		for(int j=0;j<n;j++)
		{
			cin>>tmp;
			price.push_back(tmp);
		}
		for(int j=0;j<n;j++)
		{
			cin>>tmp;
			bt.push_back(tmp);
		}
		cin>>x>>k;
		if(k!=0)
		{
			for(int j=0;j<k;j++)
			{
				cin>>tmp;
				have.push_back(tmp-1);
				mon+=price[tmp-1];
			}
		}

		go();

		printf("#%d %d\n",i,ans);

	}
}

