#include <utility>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[21][21];
int cal(int arr[21][21])
{
	int tmp=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]>tmp) tmp=arr[i][j];
		}
	}

	return tmp;
}
int tmparr[21][21];

void savemap()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			tmparr[i][j]=arr[i][j];
		}
	}
}

void unmap()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=tmparr[i][j];
		}
	}
}

int tt;

void go(int arr[21][21], int dirarr[6])
{
	int tmp[21][21];
	int k;

	for(int start=1;start<=5;start++)
	{
		int dir=dirarr[start];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				tmp[i][j]=0;
		}

		if(dir==1) // up
		{
			for(int j=0;j<n;j++)
			{
				k=0;
				for(int i=0;i<n;i++)
				{
					if(arr[i][j]!=0)
					{
						tmp[k][j]=arr[i][j];
						k++;
					}
				}
			}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					arr[i][j]=tmp[i][j];
			}

			for(int j=0;j<n;j++)
			{
				for(int i=0;i<n-1;i++)
				{
					if(arr[i][j]==arr[i+1][j])
					{
						arr[i][j]*=2;
						arr[i+1][j]=0;
						i++;
					}
				}
			}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					tmp[i][j]=0;
			}

			for(int j=0;j<n;j++)
			{
				k=0;
				for(int i=0;i<n;i++)
				{
					if(arr[i][j]!=0)
					{
						tmp[k][j]=arr[i][j];
						k++;
					}
				}
			}
		}
		else if(dir==2) // right
		{
			for(int i=0;i<n;i++)
			{
				k=n-1;
				for(int j=n-1;j>=0;j--)
				{
					if(arr[i][j]!=0)
					{
						tmp[i][k]=arr[i][j];
						k--;
					}
				}
			}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					arr[i][j]=tmp[i][j];
			}

			for(int i=0;i<n;i++)
			{
				for(int j=n-1;j>0;j--)
				{
					if(arr[i][j]==arr[i][j-1])
					{
						arr[i][j]*=2;
						arr[i][j-1]=0;
						j--;
					}	
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					tmp[i][j]=0;
			}
			for(int i=0;i<n;i++)
			{
				k=n-1;
				for(int j=n-1;j>=0;j--)
				{
					if(arr[i][j]!=0)
					{
						tmp[i][k]=arr[i][j];
						k--;
					}
				}
			}

		}
		else if(dir==3) //down
		{
			for(int j=0;j<n;j++)
			{
				k=n-1;
				for(int i=n-1;i>=0;i--)
				{
					if(arr[i][j]!=0)
					{
						tmp[k][j]=arr[i][j];
						k--;
					}
				}
			}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					arr[i][j]=tmp[i][j];
			}

			//printing();
			for(int j=0;j<n;j++)
			{
				for(int i=n-1;i>0;i--)
				{
					if(arr[i][j]==arr[i-1][j])
					{
						arr[i][j]*=2;
						arr[i-1][j]=0;
						i--;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					tmp[i][j]=0;
			}
			for(int j=0;j<n;j++)
			{
				k=n-1;
				for(int i=n-1;i>=0;i--)
				{
					if(arr[i][j]!=0)
					{
						tmp[k][j]=arr[i][j];
						k--;
					}
				}
			}
		}
		else //left
		{
			for(int i=0;i<n;i++)
			{
				k=0;
				for(int j=0;j<n;j++)
				{
					if(arr[i][j]!=0)
					{
						tmp[i][k]=arr[i][j];
						k++;
					}
				}
			}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					arr[i][j]=tmp[i][j];
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n-1;j++)
				{
					if(arr[i][j]==arr[i][j+1])
					{
						arr[i][j]*=2;
						arr[i][j+1]=0;
						j++;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					tmp[i][j]=0;
			}
			for(int i=0;i<n;i++)
			{
				k=0;
				for(int j=0;j<n;j++)
				{
					if(arr[i][j]!=0)
					{
						tmp[i][k]=arr[i][j];
						k++;
					}
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				arr[i][j]=tmp[i][j];
		}

	}

	
}

int tmax=0;
int dir[6];

void dfs(int arr[21][21], int cnt, int dir[6])
{
	tt++;

	if(cnt==5)
	{
		savemap();
		go(arr, dir);
		int tmp=cal(arr);
		if(tmax<tmp) tmax=tmp;
		unmap();
		return;
	}

	for(int i=1;i<=4;i++)
	{
		dir[cnt+1]=i;
		dfs(arr,cnt+1,dir);
	}

}

int main()
{
	cin>>n;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}

	for(int i=1;i<=4;i++)
	{
		dir[1]=i;
		dfs(arr,1,dir);
	}

	cout<<tmax;

}