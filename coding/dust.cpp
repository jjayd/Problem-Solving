#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,m,t;
int arr[52][51];
int x; //dust clearer
int sum=0;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};

void spread(){
	int tmp[51][51];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) tmp[i][j]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]>0){
				int tmpx,tmpy,cnt=0;
				int cur = arr[i][j];
				for(int k=0;k<4;k++){
					tmpx=i+dirx[k];
					tmpy=j+diry[k];
					if(tmpx<0 || tmpy<0 || tmpx>=n || tmpy>=m) continue;
					if(tmpx==x && tmpy==0) continue;
					if(tmpx==x-1 && tmpy==0) continue;
					tmp[tmpx][tmpy]+=cur/5;
					cnt++;
				}
				tmp[i][j]+=cur-cnt*(cur/5);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) arr[i][j]=tmp[i][j];
	}
}

void rotate(){
	for(int i=x-3;i>=0;i--) arr[i+1][0]=arr[i][0];
	for(int j=1;j<m;j++) arr[0][j-1]=arr[0][j];
	for(int i=1;i<=x-1;i++) arr[i-1][m-1]=arr[i][m-1];
	for(int j=m-2;j>0;j--) arr[x-1][j+1]=arr[x-1][j];
	arr[x-1][1]=0;

	for(int i=x+2;i<n;i++) arr[i-1][0]=arr[i][0];
	for(int j=1;j<m;j++) arr[n-1][j-1]=arr[n-1][j];
	for(int i=n-1;i>=x+1;i--) arr[i][m-1]=arr[i-1][m-1];
	for(int j=m-2;j>0;j--) arr[x][j+1]=arr[x][j];
	arr[x][1]=0;	
}

int main(){
	cin>>n>>m>>t;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==-1) x=i;
		}
	}
	for(int i=0;i<t;i++){
		spread();
		rotate();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]>0) sum+=arr[i][j];
		}
	}
	printf("%d\n",sum);
}