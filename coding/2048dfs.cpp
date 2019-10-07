#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[21][21];
int tmp[21][21];
int tmax = 0;

void printing(int cnt)
{
	printf("cnt:%d\n",cnt);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

int cal()
{
	int tmp=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(arr[i][j]>tmp) tmp=arr[i][j];
		}
	}
	return tmp;
}

void savemap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j];
	}
}

void unmap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = tmp[i][j];
	}
}

void shifting(int arr[21][21], int dir)
{
	
	if (dir == 0) // up
	{
		for (int j = 0; j < n; j++)
		{
			vector<int> v;
			for (int i = 0; i < n; i++)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}
			for (int i = 0; i < v.size(); i++)
				arr[i][j] = v[i];
		
			for (int i = v.size(); i < n; i++)
				arr[i][j] = 0;
		}

		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n-1; i++)
			{
				if (arr[i][j] == arr[i + 1][j])
				{
					arr[i][j] *= 2;
					arr[i + 1][j] = 0;
					i++;
				}
			}
		}

		for (int j = 0; j < n; j++)
		{
			vector<int> v;
			for (int i = 0; i < n; i++)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}

			for (int i = 0; i < v.size(); i++)
				arr[i][j] = v[i];
		
			for (int i = v.size(); i < n; i++)
				arr[i][j] = 0;
		}
	}
	else if (dir == 1) //right
	{
		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			for (int j = n-1; j >=0; j--)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}
			for (int j = 0; j < v.size(); j++)
				arr[i][n-j] = v[j];
		
			for (int j = v.size(); j < n; j++)
				arr[i][n-j-1] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j >=0; j--)
			{
				if (arr[i][j] == arr[i][j-1])
				{
					arr[i][j] *= 2;
					arr[i][j-1] = 0;
					j--;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			for (int j = n-1; j >=0; j--)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}
			for (int j = 0; j < v.size(); j++)
				arr[i][n-j] = v[j];
		
			for (int j = v.size(); j < n; j++)
				arr[i][n-j-1] = 0;
		}

	
	}
	else if (dir == 2) // down
	{
		for (int j = 0; j < n; j++)
		{
			vector<int> v;
			for (int i = n-1; i >=0; i--)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}
			for (int i = 0; i < v.size(); i++)
				arr[n-i][j] = v[i];
		
			for (int i = v.size(); i < n; i++)
				arr[n-i-1][j] = 0;
		}

		for (int j = 0; j < n; j++)
		{
			for (int i = n-1; i >=0; i--)
			{
				if (arr[i][j] == arr[i - 1][j])
				{
					arr[i][j] *= 2;
					arr[i - 1][j] = 0;
					i--;
				}
			}
		}

		for (int j = 0; j < n; j++)
		{
			vector<int> v;
			for (int i = n-1; i >=0; i--)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}
			for (int i = 0; i < v.size(); i++)
				arr[n-i][j] = v[i];
		
			for (int i = v.size(); i < n; i++)
				arr[n-i-1][j] = 0;
		}
	}
	else //left
	{
		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}
			for (int j = 0; j < v.size(); j++)
				arr[i][j] = v[j];
		
			for (int j = v.size(); j < n; j++)
				arr[i][j] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n-1; j++)
			{
				if (arr[i][j] == arr[i][j+1])
				{
					arr[i][j] *= 2;
					arr[i ][j+1] = 0;
					j++;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] != 0)
					v.push_back(arr[i][j]);
			}
			for (int j = 0; j < v.size(); j++)
				arr[i][j] = v[j];
		
			for (int j = v.size(); j < n; j++)
				arr[i][j] = 0;
		}
	}
}

void dfs(int arr[21][21], int cnt, int dir[5])
{
	if (cnt == 5)
	{
		savemap();
		for(int i=0;i<5;i++)
			printf("%d ",dir[i]);
		printf("\n");
		for(int i=0;i<5;i++)
			shifting(arr,dir[i]);
		unmap();

		int tmp = cal();
		if (tmp > tmax) tmax = tmp;
	//	cout << tmax;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		dir[cnt]=i;
		dfs(arr, cnt+1,dir);
	}

	
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	int dir[5];

	dfs(arr,0,dir);


}