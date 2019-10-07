#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
vector<int> arr;
int ans;

void go()
{
	for(int i=0;i<n;i++)
	{
		int sum=0;
		int ptr=0;
		while(1)
		{
			if(i+ptr>=n) break;
			sum+=arr[i+ptr];
			if(sum==m)
			{
			//	printf("ans: %d\n",i);
				ans++;
				break;
			}
			else if(sum>m)
			{
				break;
			}
			ptr++;
		}
	}
}


int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m;
		ans=0;
		arr.clear();
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			arr.push_back(tmp);
		}

		go();	

		printf("#%d %d\n",i,ans);

	}
}

