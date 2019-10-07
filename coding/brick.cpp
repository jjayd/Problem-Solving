#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <stdio.h>

using namespace std;

int n, w, h;
int tmin;
int nblock = 0;

int arr[20][20];
int tmparr[20][20];
vector<pair<int, int> > bomb;

void printing()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

void savemap()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			tmparr[i][j] = arr[i][j];
	}
}

void remap()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			arr[i][j] = tmparr[i][j];
	}
}

int cal()
{
	int tmp = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] != 0)
				tmp++;
		}
	}
	return tmp;
}

void make_zero()
{
	for (int j = 0; j < w; j++)
	{
		vector<int> tmp;
		for (int i = h - 1; i >= 0; i--)
		{
			if (arr[i][j] != 0)
			{
				tmp.push_back(arr[i][j]);
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < tmp.size(); i++)
			arr[h-1-i][j] = tmp[i];
	}
}

int go(int dir[4])
{
	int tmpblock = nblock;

	for (int t = 0; t < n; t++)
	{
		int chk[20][20];
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				chk[i][j] = 0;
		}

		int y = dir[t];
		for (int i = 0; i < h; i++)
		{
			if (arr[i][y] != 0)
			{
				bomb.push_back(make_pair(i,y));
				chk[i][y] = 1;
				break;
			}
		}


		while (!bomb.empty())
		{
			int a = bomb[0].first;
			int b = bomb[0].second;

			if (arr[a][b] == 0)
			{
				bomb.erase(bomb.begin());
				continue;
			}
			
			int size = arr[a][b];
			arr[a][b] = 0;
			chk[a][b] = 1;
			tmpblock--;

			if (tmpblock == 0) return 0;
		
			for (int i = 1; i < size; i++)
			{
				if (a + i < h && arr[a + i][b] != 0 && chk[a + i][b] == 0)
				{
					chk[a + i][b] = 1;
					if (arr[a + i][b]>1) bomb.push_back(make_pair(a + i, b));
				}
				if (a - i >= 0 && arr[a - i][b] != 0 && chk[a - i][b] == 0)
				{
					chk[a - i][b] = 1;
					if (arr[a - i][b]>1) bomb.push_back(make_pair(a - i, b));
				}
				if (b + i < w && arr[a][b + i] != 0 && chk[a][b + i] == 0)
				{
					chk[a][b+i] = 1;
					if (arr[a][b+i]>1) bomb.push_back(make_pair(a, b + i));
				}
				if (b - i >= 0 && arr[a][b - i] != 0 && chk[a][b - i] == 0)
				{
					chk[a][b-i] = 1;
					if (arr[a][b-i]>1) bomb.push_back(make_pair(a, b - i));
				}
			}
			bomb.erase(bomb.begin());
		}
		make_zero();
		cout << endl;
		
	}

	return cal();

}

void dfs(int cnt,int dir[4])
{
	if (cnt == n)
	{
		savemap();
		int tmp = go(dir);
		remap();
		
		if (tmp < tmin) tmin = tmp;
		return;
		
	}
	for (int i = 0; i < w; i++)
	{
		dir[cnt] = i;
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
		nblock = 0;
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				cin >> arr[j][k];
				if (arr[j][k] != 0) nblock++;
			}
		}
		int dir[4];
		dfs(0,dir);
		cout << "#" << i << " " << tmin << endl;
	}
	return 0;
}