#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int r,c,m;
vector<pair<int,pair<int,int> > > arr[100][100]; //[size, [fast, dir] ]

int sum=0;
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};

void catchshark(int col){
	printf("col:%d\n",col);
	for(int i=0;i<r;i++){
		if(arr[i][col].size()!=0){
			sum+=arr[i][col][0].first;
			printf("erase: (%d %d)\n",i,col);
			arr[i][col].clear();
			printf("tmpsum: %d\n",sum);
			return;
		}
	}
	printf("\n");

}

void printing(){
	for(int i=0;i<=r;i++){
		for(int j=0;j<=c;j++){
			for(int k=0;k<arr[i][j].size();k++){
				printf("%d %d %d %d %d\n",i,j,arr[i][j][k].first,arr[i][j][k].second.first,arr[i][j][k].second.second);
			}
		}
	}
}

void move(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j].size()==1){

				int size = arr[i][j][0].first;
				int fast = arr[i][j][0].second.first;

				int s = arr[i][j][0].second.first;
				int d = arr[i][j][0].second.second;
				arr[i][j].clear();
				if(d==0 || d==1) s = s%((r-1)*2);
				else s = s%((c-1)*2);
				
				int tmpx = i+dirx[d]*s;
				int tmpy = j+diry[d]*s;

				if(tmpx>=r){
					if(tmpx<2*(r-1)){
						tmpx = 2*(r-1) - tmpx;
						d=0;
					}else{
						tmpx = tmpx-2*(r-1);
					}
				}
				else if(tmpx<0){
					tmpx = abs(tmpx);
					if(tmpx<2*(r-1)){
						d=1;
					}else{
						tmpx = 2*(r-1)+1-tmpx;
					}
				}
				else if(tmpy>=c){
					if(tmpy<2*(c-1)){
						tmpy = 2*(c-1) - tmpy;
						d=4;
					}else{
						tmpy = tmpy-2*(c-1);
					}
				}
				else if(tmpy<0){
					tmpy = abs(tmpy);
					if(tmpy<2*(c-1)){
						d=3;
					}else{
						tmpy = 2*(c-1)+1-tmpy;
					}
				}
				arr[tmpx][tmpy].push_back({size,{fast,d}});

			}
		}
	}

	//eating
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j].size()>1){
				sort(arr[i][j].begin(),arr[i][j].end());
				reverse(arr[i][j].begin(),arr[i][j].end());
				arr[i][j].erase(arr[i][j].begin()+1);
			}
		}
	}

}


int main(){
	cin>>r>>c>>m;
	int x,y,s,d,z;

	for(int i=0;i<m;i++){
		cin>>x>>y>>s>>d>>z;
		arr[x-1][y-1].push_back({z,{s,d-1}});
	}

	for(int fisher=0;fisher<c;fisher++){
		catchshark(fisher);
		move();
		printing();
	}

	printf("%d\n",sum);
}