#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

int n, w, h;
int tmin;

int arr[20][20];
int tmparr[20][20];

void savemap()
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
			tmparr[i][j] = arr[i][j];
	}
}

void remap()
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
			arr[i][j] = tmparr[i][j];
	}
}

int cal()
{
	int tmp = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (arr[i][j] != 0)
				tmp++;
		}
	}
	return tmp;
}

vector<pair<int, int> > bomb;

void make_zero()
{
	for (int i = 0; i < w; i++)
	{
		vector<int> tmp;
		for (int j = h - 1; j >= 0; j--)
		{
			if (arr[i][j] != 0)
			{
				tmp.push_back(arr[i][j]);
				arr[i][j] = 0;
			}
		}
		for (int j = 0; j < tmp.size(); j++)
			arr[i][h - 1 - j] = tmp[j];
	}
}

void go(int dir[4])
{
	for (int t = 0; t < n; t++)
	{
		int x = dir[t];
		for (int i = 0; i < h; i++)
		{
			if (arr[x][i] != 0)
			{
				bomb.push_back(make_pair(x, i));
				break;
			}
		}
		while (!bomb.empty())
		{
			int a = bomb[0].first;
			int b = bomb[0].second;
			arr[a][b] = 0;
			int size = arr[a][b];
			for (int i = 1; i < size; i++)
			{
				if (a + i < w && arr[a + i][b] != 0)
				{
					arr[a + i][b] = 0;
					bomb.push_back(make_pair(a + i, b));
				}
				if (a - i >= 0 && arr[a - i][b] != 0)
				{
					arr[a - i][b] = 0;
					bomb.push_back(make_pair(a + i, b));
				}
				if (b + i < h && arr[a][b + i] != 0)
				{
					arr[a][b+i] = 0;
					bomb.push_back(make_pair(a + i, b));
				}
				if (b - i >= 0 && arr[a][b - i] != 0)
				{
					arr[a][b-i] = 0;
					bomb.push_back(make_pair(a + i, b));
				}
			}
			bomb.erase(bomb.begin());
		}
		make_zero();
	}
}

void dfs(int cnt,int dir[4])
{
	if (cnt == n)
	{
		savemap();
		go(dir);
		remap();

		int tmp=cal();
		if (tmp < tmin) tmin = tmp;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		dir[cnt] = n;
		dfs(cnt + 1, dir);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> w >> h;
		tmin = 99999999;
		for (int j = 0; j < w; j++)
		{
			for (int k = 0; k < h; k++)
				cin >> arr[j][k];
		}
		int dir[4];
		dfs(0,dir);
		cout << "#" << i << " " << tmin << endl;
	}
	return 0;
}