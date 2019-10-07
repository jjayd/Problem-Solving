#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
int n,m;
char arr[10][10];
int bx,by,rx,ry;
int ans=-1;
vector<pair<int,pair<pair<int,int>, pair<int,int> > > > stack; 

int main(){
	cin>>n>>m;
	char tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>tmp;
			if(tmp=='B'){
				bx=i;
				by=j;
				tmp='.';
			}
			else if(tmp=='R'){
				rx=i;
				ry=j;
				tmp='.';
			}
			arr[i][j]=tmp;
		}
	}

	stack.push_back({0,{{rx,ry},{bx,by}}});

	while(!stack.empty()){
		int cnt = stack[0].first;
		if(cnt==10) break;
		rx = stack[0].second.first.first;
		ry = stack[0].second.first.second;
		bx = stack[0].second.second.first;
		by = stack[0].second.second.second;
		stack.erase(stack.begin());
		int zrx,zry,zbx,zby;

		for(int dir=0;dir<4;dir++){
			int chk1=0;
			int chk2=0;
			zrx=rx;	zry=ry;	zbx=bx;	zby=by;
			if(dir==0){ //up
				for(int i=rx-1;i>=0;i--){
					if(arr[i][ry]=='O') chk1=1;
					else if(arr[i][ry]=='.') zrx=i; 
					else break;
				}

				for(int i=bx-1;i>=0;i--){
					if(arr[i][by]=='O') chk2=1;
					else if(arr[i][by]=='.') zbx=i;
					else break;
				}

				if(zry==zby && zrx==zbx){
					if(rx<bx) zbx++;
					else if(rx>bx) zrx++;
				}

				if(chk2==1) continue;
				else if(chk1==1){
					ans=cnt+1;
					break;
				}
			}
			else if(dir==1){ //down
				for(int i=rx+1;i<n;i++){
					if(arr[i][ry]=='O') chk1=1;
					else if(arr[i][ry]=='.') zrx=i; 
					else break;
				}

				for(int i=bx+1;i<n;i++){
					if(arr[i][by]=='O') chk2=1;
					else if(arr[i][by]=='.') zbx=i;
					else break;
				}

				if(zry==zby && zrx==zbx){
					if(rx<bx) zrx--;
					else if(rx>bx) zbx--;
				}
				if(chk2==1) continue;
				else if(chk1==1){
					ans=cnt+1;
					break;
				}
			}
			else if(dir==2){ //left
				for(int i=ry-1;i>=0;i--){
					if(arr[rx][i]=='O') chk1=1;
					else if(arr[rx][i]=='.') zry=i; 
					else break;
				}
				for(int i=by-1;i>=0;i--){
					if(arr[bx][i]=='O') chk2=1;
					else if(arr[bx][i]=='.') zby=i;
					else break;
				}
				if(zrx==zbx && zry==zby){
					if(ry<by) zby++;
					else if(ry>by) zry++;
				}

				if(chk2==1) continue;
				else if(chk1==1){
					ans=cnt+1;
					break;
				}
			}
			else{ //right
				for(int i=ry+1;i<m;i++){
					if(arr[rx][i]=='O') chk1=1;
					else if(arr[rx][i]=='.') zry=i; 
					else break;
				}

				for(int i=by+1;i<m;i++){
					if(arr[bx][i]=='O') chk2=1;
					else if(arr[bx][i]=='.') zby=i;
					else break;
				}

				if(zrx==zbx && zry==zby){
					if(ry<by) zry--;
					else if(ry>by) zby--;
				}
				if(chk2==1) continue;
				else if(chk1==1){
					ans=cnt+1;
					break;
				}
			}
			if(zrx==rx && zry==ry && zbx==bx && zby==by) continue;
			stack.push_back({cnt+1,{{zrx,zry},{zbx,zby}}});
		}

		if(ans!=-1) break;

		sort(stack.begin(),stack.end());
		stack.erase(unique(stack.begin(),stack.end()),stack.end());
		
	}

	printf("%d\n",ans);
}