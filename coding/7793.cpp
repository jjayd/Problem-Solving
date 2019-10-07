#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int n,m;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
char arr[50][50];
int ans=100000000;


void run(vector<pair<int,int> > devil, int sx, int sy, int cnt, int (*devilchk)[51], int (*suyoenchk)[51])
{
	printf("start!\n");
	printf("(%d %d), cnt: %d\n",sx,sy,cnt);
	vector<pair<int,int> > tmpdevil;
	vector<pair<int,int> > tmp;
	
	for(int i=0;i<devil.size();i++)
	{
		for(int j=0;j<4;j++)
		{
			int tmpx = devil[i].first+dirx[j];
			int tmpy = devil[i].second+diry[j];

			if(tmpx<n && tmpx>=0 && tmpy<m && tmpy>=0 && devilchk[tmpx][tmpy]==0 && arr[tmpx][tmpy]!='X' && arr[tmpx][tmpy]!='D')
			{
				printf("pushdevil\n %d %d\n",tmpx,tmpy);
				devilchk[tmpx][tmpy]=1;
				tmpdevil.push_back(make_pair(tmpx,tmpy));
			}

		}
	}

	for(int j=0;j<4;j++)
	{
		int tmpx = sx+dirx[j];
		int tmpy = sy+diry[j];
		printf("\t%[%d] %d %d cnt: %d\n",j,tmpx,tmpy,cnt);
		printf("%d %d %d\n", devilchk[tmpx][tmpy]==0 , arr[tmpx][tmpy]!='X' , suyoenchk[tmpx][tmpy]==0);
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<m;b++)
				printf("%d",devilchk[a][b]);
			printf("\n");
		}
		printf("\n\n");
		for(int a=0;a<tmpdevil.size();a++)
			printf("%d %d\n",tmpdevil[a].first,tmpdevil[a].second);


		if(tmpx<n && tmpx>=0 && tmpy<m && tmpy>=0 && devilchk[tmpx][tmpy]==0 && arr[tmpx][tmpy]!='X' && suyoenchk[tmpx][tmpy]==0)
		{
			
			if(arr[tmpx][tmpy]=='D')
			{
		//		printf("%d %d\n",tmpx,tmpy);
				if(cnt+1<ans) ans=cnt+1;
				return;
			}
			else
			{
				suyoenchk[tmpx][tmpy]=1;
				run(tmpdevil,tmpx,tmpy,cnt+1,devilchk,suyoenchk);
				suyoenchk[tmpx][tmpy]=0;
			}
			
		}
		
	}
	return;
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m;
		int sx,sy;
		int devilchk[51][51];
		int suyoenchk[51][51];
		ans=100000000;
		vector<pair<int,int> > devil;
		vector<pair<int,int> > suyoen;

		for(int j=0;j<n;j++)
		{
			string tmp;
			cin>>tmp;
			for(int k=0;k<m;k++)
			{
				arr[j][k]=tmp[k];
				devilchk[j][k]=0;
				suyoenchk[j][k]=0;
				
				if(arr[j][k]=='S')
				{
					sx=j;
					sy=k;
					suyoenchk[j][k]=1;
				}
				else if(arr[j][k]=='*')
				{
					devil.push_back(make_pair(j,k));
					devilchk[j][k]=1;
				}
			}
		}

		run(devil,sx,sy,0,devilchk,suyoenchk);
		if(ans==100000000)
			printf("#%d GAME OVER\n",i);
		else
			printf("#%d %d\n",i,ans);
	}
}