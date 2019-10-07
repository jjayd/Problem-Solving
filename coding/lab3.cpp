#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int,int> > virus;

int n,m;
int arr[51][51];
int tmin=99999999;
int numvirus;
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};

int run(int* chk){
	vector<pair<int, pair<int,int> > > pp;
	int visit[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			visit[i][j]=0;
	}

	for(int i=0;i<numvirus;i++){
		if(chk[i]==1){
			pp.push_back({0,{virus[i].first,virus[i].second}});
			visit[virus[i].first][virus[i].second]=1;
		}
	}

	int time=0;
	int ans=0;
	while(!pp.empty()){
		int num=0;
		time = pp[0].first;		
		int x = pp[0].second.first;
		int y = pp[0].second.second;
		pp.erase(pp.begin());
//		if(arr[x][y]!=2) ans=time;

		for(int i=0;i<4;i++){
			int tmpx = x+dirx[i];
			int tmpy = y+diry[i];
			if(tmpx<0 || tmpy<0 || tmpx>=n || tmpy>=n) continue;
			if(arr[tmpx][tmpy]==1) continue;
			if(visit[tmpx][tmpy]==1) continue;
			visit[tmpx][tmpy]=1;
			pp.push_back({time+1,{tmpx,tmpy}});
		}

		int cnt=0;
		for(int i=0;i<pp.size();i++){
			if(arr[pp[i].second.first][pp[i].second.second]==2) cnt++;
			else break;
		}
		if(cnt==pp.size()) break;
	}

	int chkk=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visit[i][j]==1 || arr[i][j]==1 || arr[i][j]==2) continue;
			else{
				chkk=1;
				goto a;
			}
		}
	}
a:
	if(chkk==1) time=-1;
	return time;
}

void select(int cnt, int* chk, int ptr){
	if(cnt==m){
		int tmp = run(chk);
		if(tmp==-1) return;
		if(tmp<tmin) tmin=tmp;
		return;
	}

	for(int i=ptr;i<numvirus;i++){
		chk[i]=1;
		select(cnt+1,chk,i+1);
		chk[i]=0;
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==2) virus.push_back({i,j});
		}
	}
	numvirus = virus.size();
	int chk[numvirus]={0};
	select(0,chk,0);
	if(tmin==99999999) printf("-1\n");
	else printf("%d\n",tmin);
	return 0;
}
//numvirus C m