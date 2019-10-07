#include <iostream>
#include <algorithm>

using namespace std;
int t[16];
int p[16];
int n;
int tmp;
int ans;

void dfs(int index)
{
	for (int i = index; i <= n; i++)
	{
		if (i + t[i] <= n+1)
		{
			tmp += p[i];
			ans = max(ans, tmp);
            dfs(i + t[i]);
			tmp -= p[i];
		}
	}
	if (index >= n) return;
}


int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d",&t[i],&p[i]);

	dfs(1);

	printf("%d",ans);

	return 0;
}