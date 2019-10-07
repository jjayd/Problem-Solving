#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n;
		int ans;
		vector<int> v;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			v.push_back(tmp);
		}

		if(v.size()==1) ans=v[0]*v[0];
		else
		{
			int min,max;
			sort(v.begin(),v.end());
			max=v[v.size()-1];
			min=v[0];
			ans=min*max;
		}

		printf("#%d %d\n",i,ans);
	}
}