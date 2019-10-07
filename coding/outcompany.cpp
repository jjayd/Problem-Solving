#include <iostream>
#include <algorithm>

using namespace std;

int arr[17][2];
int n;
int price;
int ans;

void dfs(int day)
{
	for(int i=day;i<=n;i++)
	{
		if(i+arr[i][0] <=n+1)
		{
			price+=arr[i][1];
			ans = max(ans,price);
		//	day=i+arr[i][0];
			dfs(i+arr[i][0]);
			price-=arr[i][1];
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i][0]>>arr[i][1];

	dfs(1);

	cout<<ans;
}