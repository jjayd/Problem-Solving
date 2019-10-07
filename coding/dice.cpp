#include <iostream>

using namespace std;

int n,m,k;
int arr[21][21];
int x,y;
int order[1001];
int dice[7]; // 1 2 3 4 5 6 -> 바닥은 dice[6]
int out=0;
int tmp[7];
int dir_x[4]={1,0,-1,0};
int dir_y[4]={0,1,0,-1};


void cal(int dir)
{
	//printf("arr[%d][%d]: %d dir:%d\n",x,y,arr[x][y],dir);

	if(arr[x][y]==0) arr[x][y]=tmp[6];
	else
	{
		tmp[6]=arr[x][y];
		arr[x][y]=0;
	}
}

void rolling(int dir) // 동1 서2 북3 남4
{
	if(dir==1)
	{
		if(y+1>=m)
		{
			out=1;
			return;
		}
		y++;

		tmp[1]=dice[4];
		tmp[2]=dice[2];
		tmp[3]=dice[1];
		tmp[4]=dice[6];
		tmp[5]=dice[5];
		tmp[6]=dice[3];

		cal(dir);

		for(int i=1;i<=6;i++)
			dice[i]=tmp[i];

	}
	else if(dir==2)
	{
		if(y-1<0)
		{
			out=1;
			return;
		}
		y--;
		
		tmp[1]=dice[3];
		tmp[2]=dice[2];
		tmp[3]=dice[6];
		tmp[4]=dice[1];
		tmp[5]=dice[5];
		tmp[6]=dice[4];

		cal(dir);
		
		for(int i=1;i<=6;i++)
			dice[i]=tmp[i];

	}
	else if(dir==3)
	{
		if(x-1<0)
		{
			out=1;
			return;
		}
		x--;
	
		tmp[1]=dice[5];
		tmp[2]=dice[1];
		tmp[3]=dice[3];
		tmp[4]=dice[4];
		tmp[5]=dice[6];
		tmp[6]=dice[2];

		cal(dir);
		
		for(int i=1;i<=6;i++)
			dice[i]=tmp[i];

	}
	else if(dir==4)
	{
		if(x+1>=n)
		{
			out=1;
			return;
		}
		x++;
	
		tmp[1]=dice[2];
		tmp[2]=dice[6];
		tmp[3]=dice[3];
		tmp[4]=dice[4];
		tmp[5]=dice[1];
		tmp[6]=dice[5];

		cal(dir);
		
		for(int i=1;i<=6;i++)
			dice[i]=tmp[i];

	}
}

int main()
{
	cin>>n>>m>>x>>y>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	}
	for(int i=0;i<k;i++)
		cin>>order[i];

	for(int i=0;i<k;i++)
	{
		rolling(order[i]);
		if(out==1)
		{
			out=0;
			continue;
		}
		cout<<dice[1]<<endl;
	}

}