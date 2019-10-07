#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000][1000];
int ans2[1000][1000];
int ans5[1000][1000];
int n;
int tmin;



int chk2(int x)
{
	int cnt=0;
	while(1)
	{
		if(x%2==0)
		{
			cnt++;
			x=x/2;
		}
		else break;
	}
	return cnt;
}

int chk5(int x)
{
	int cnt=0;
	while(1)
	{
		if(x%5==0)
		{
			cnt++;
			x=x/5;
		}
		else break;
	}
	return cnt;
}


void run()
{
	int two,five;

	ans2[0][0] = chk2(arr[0][0]);
	ans5[0][0] = chk5(arr[0][0]);

	for(int i=1;i<n;i++)
	{
		if(arr[0][i]==0)
		{
			ans2[0][i]=-1;
			ans5[0][i]=-1;
			continue;
		}
		two = chk2(arr[0][i]);
		five = chk5(arr[0][i]);
		
		if(ans2[0][i-1]!=-1) ans2[0][i] = ans2[0][i-1] + two;
		else ans2[0][i]=-1;
		if(ans2[0][i-1]!=-1) ans5[0][i] = ans5[0][i-1] + five;
		else ans5[0][i]=-1;

	}

	for(int i=1;i<n;i++)
	{
		if(arr[i][0]==0)
		{
			ans2[i][0]=-1;
			ans5[i][0]=-1;
			continue;
		}
		two = chk2(arr[i][0]);
		five = chk5(arr[i][0]);

		if(ans2[i-1][0]!=-1) ans2[i][0] = ans2[i-1][0] + two;
		else ans2[i][0]=-1;
		if(ans5[i-1][0]!=-1) ans5[i][0] = ans5[i-1][0] + five;
		else ans5[i][0]=-1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
		//	printf("(%d %d)\n",i,j);
			if(arr[i][j]==0)
			{
				ans2[i][j]=-1;
				ans5[i][j]=-1;
				continue;
			}
			two = chk2(arr[i][j]);
			five = chk5(arr[i][j]);
			if(ans2[i-1][j]==-1 && ans2[i][j-1]==-1)
			{
				ans2[i][j]=-1; ans5[i][j]=-1; continue;
			}
			else if(ans2[i-1][j]==-1)
			{
				ans2[i][j]=ans2[i][j-1]+two;
				ans5[i][j]=ans5[i][j-1]+five;
				continue;
			}
			else if(ans2[i][j-1]==-1)
			{
				ans2[i][j]=ans2[i-1][j]+two;
				ans5[i][j]=ans5[i-1][j]+five;
				continue;
			}

			int tmp1 = min(ans2[i-1][j]+two,ans5[i-1][j]+five);
			int tmp2 = min(ans2[i][j-1]+two,ans5[i][j-1]+five);
	//		printf("A\n");
			if(tmp1==tmp2)
			{
	//			printf("1\n");
				if(max(ans2[i-1][j]+two,ans5[i-1][j]+five) > max(ans2[i][j-1]+two,ans5[i][j-1]+five))
				{
					ans2[i][j]=ans2[i][j-1]+two;
					ans5[i][j]=ans5[i][j-1]+five;
				}
				else
				{
					ans2[i][j]=ans2[i-1][j]+two;
					ans5[i][j]=ans5[i-1][j]+five;
				}

			}
			else if(tmp1>tmp2)
			{
	//			printf("2\n");
				ans2[i][j]=ans2[i][j-1]+two;
				ans5[i][j]=ans5[i][j-1]+five;
			}
			else if(tmp1<tmp2)
			{
	//			printf("3\n");
				ans2[i][j]=ans2[i-1][j]+two;
				ans5[i][j]=ans5[i-1][j]+five;
			}

		}
	}
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				cin>>arr[j][k];
			}
		}

		run();

/*		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
				printf("%d/%d ",ans2[j][k],ans5[j][k]);
			printf("\n");
		}

*/
		printf("#%d %d\n",i,min(ans2[n-1][n-1],ans5[n-1][n-1]));

	}
}