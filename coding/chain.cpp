#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int arr[5][10];
int k;
int chk[5];
int cnt=1;
int turn[4];

void fin()
{
	int tmp[8];
	for(int i=1;i<=4;i++)
	{
		if(turn[i]==1)
		{
			for(int j=0;j<7;j++)
			{
				tmp[j+1]=arr[i][j];
			}
			tmp[0]=arr[i][7];
			for(int j=0;j<8;j++)
				arr[i][j]=tmp[j];
		}
		else if(turn[i]==-1)
		{
			for(int j=0;j<7;j++)
			{
				tmp[j]=arr[i][j+1];
			}
			tmp[7]=arr[i][0];

			for(int j=0;j<8;j++)
				arr[i][j]=tmp[j];
		}
	}
}

void rotate(int x)
{
	if(cnt==4)
	{
		fin();
		return;
	}	
	if(x-1>=1 && chk[x-1]==0)
	{
		chk[x-1]=1;
		cnt++;
		if(arr[x][6]!=arr[x-1][2]) turn[x-1]=-turn[x];
		else turn[x-1]=0;
		rotate(x-1);
	}
	if(x+1<5 && chk[x+1]==0)
	{
		chk[x+1]=1;
		cnt++;
		if(arr[x][2]!=arr[x+1][6]) turn[x+1]=-turn[x];
		else turn[x+1]=0;
		rotate(x+1);
	}
}

int main()
{
	for(int i=1;i<=4;i++)
	{
		int tmp;
		cin>>tmp;
		for(int j=0;j<8;j++)
		{
			arr[i][7-j]=tmp%10;
			tmp=tmp/10;
		}

	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		turn[a]=b;
		cnt=1;
		for(int i=1;i<=4;i++) chk[i]=0;
		chk[a]=1;
		
		rotate(a);
	}

	cout<<arr[1][0]+arr[2][0]*2+arr[3][0]*4+arr[4][0]*8;

}