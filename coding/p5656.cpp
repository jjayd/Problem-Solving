#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int n,w,h;
int tmin;
int arr[20][20]; //arr[h][w]
int tmparr[20][20];
int chk[5];

typedef struct point{
	int x;
	int y;
	int n;
}point;

void cp(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++) tmparr[i][j]=arr[i][j];
	}
}

void print(){
	cout<<endl;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++) cout<<tmparr[i][j]<<" ";
			cout<<endl;
	}
	cout<<endl;
}

int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};

void down(){
	int savearr[20][20];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			savearr[i][j]=tmparr[i][j];
			tmparr[i][j]=0;
		} 
	}
	for(int i=0;i<w;i++){
		int cnt=0;
		for(int j=h-1;j>=0;j--){
			if(savearr[j][i]!=0){
				tmparr[h-1-cnt][i]=savearr[j][i];
				cnt++;
			}
		}
	}
	return;
}

void remove(int ptr){
	vector<point> p;
	for(int i=0;i<h;i++){
		if(tmparr[i][ptr]!=0){
			point tmpp;
			tmpp.x=i;
			tmpp.y=ptr;
			tmpp.n=tmparr[i][ptr];
			if(tmpp.n==1){
				tmparr[i][ptr]=0;
				break;
			}
			p.push_back(tmpp);
			tmparr[i][ptr]=0;
			break;
		}
	}
	while(!p.empty()){
		int x=p[0].x;
		int y=p[0].y;
		int n=p[0].n;
		printf("%d %d: %d\n",x,y,n);
		for(int i=0;i<4;i++){
			for(int j=1;j<n;j++){
				int tmpx = x+dirx[i]*j;
				int tmpy = y+diry[i]*j;
				if(tmpx<0 || tmpy<0 || tmpx>=h || tmpy>=w) continue;
				if(tmparr[tmpx][tmpy]==0) continue;
				if(tmparr[tmpx][tmpy]==1){
					tmparr[tmpx][tmpy]=0;
					continue;
				}
				p.push_back({tmpx,tmpy,tmparr[tmpx][tmpy]});
				tmparr[tmpx][tmpy]=0;
			}
		}
		p.erase(p.begin());
	}
	down();
}

int count(){
	int ans=0;
	cp();
	for(int i=0;i<n;i++){
		remove(chk[i]);
	//	printf("---------------");
	//	print();
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(tmparr[i][j]!=0) ans++;
		}
	}
	return ans;
}

void dfs(int ptr){
	if(ptr==n){
		int tmp = count();
		if(tmp<tmin) tmin=tmp;
		return;
	}

	for(int j=0;j<w;j++){
		chk[ptr]=j;
		dfs(ptr+1);
	}

}

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>w>>h;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++) cin>>arr[i][j];
		}
		tmin=999999999;

		dfs(0);
		cout<<"#"<<t<<" "<<tmin<<endl;
	}

}