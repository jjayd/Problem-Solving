#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int x,y,d,g;
int arr[101][101];
vector<pair<int,int> > dragon[20];
vector<pair<int,int> > info;
int dirx[4] = {1,0,-1,0};
int diry[4] = {0,-1,0,1};
int where;
int sum=0;

void run(){
	for(int n=0;n<N;n++){
		x = dragon[n][0].first;
		y = dragon[n][0].second;
		arr[x][y]=1;
		d = info[n].first;
		arr[x+dirx[d]][y+diry[d]]=1;
		dragon[n].push_back({x+dirx[d],y+diry[d]});

		for(g=1;g<=info[n].second;g++){
			int size=dragon[n].size();
			int px = dragon[n][size-1].first; //center
			int py = dragon[n][size-1].second;

			for(int i=size-2;i>=0;i--){
				x = dragon[n][i].first - px;
				y = dragon[n][i].second - py; 
				int tmpx,tmpy;
				if(x < 0 && y <= 0){ // 1
					tmpx = px-y; 
					tmpy = py+x;
				}else if(x >=0 && y<0){ // 2
					tmpx = px-y;
					tmpy = py+x; 
				}else if(x >0 && y>=0){ // 3
					tmpx = px-y; 
					tmpy = py+x;
				}else if(x <=0 && y >0){ //4 
					tmpx = px-y; 
					tmpy = py+x;
				}
				if(tmpx>=0 && tmpy>=0 && tmpx<=100 && tmpy<=100){
					dragon[n].push_back({tmpx,tmpy});
					arr[tmpx][tmpy]=1;
				}
			}

		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>x>>y>>d>>g;
		dragon[i].push_back({x,y});
		info.push_back({d,g});
	}

	run();

	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			int cnt=0;
			if(arr[i][j]==1) cnt++;
			if(arr[i][j+1]==1) cnt++;
			if(arr[i+1][j]==1) cnt++;
			if(arr[i+1][j+1]==1) cnt++;
			if(cnt==4) sum++;
		}
	}
	printf("%d\n",sum);
}