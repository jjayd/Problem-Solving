#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int r,c;
string arr[21];

int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
int tmax;
int maxans;
typedef class node{
public:
	int x;
	int y;
}Node;
int m[26];
int chk[20][20];
vector<char> alpha;

vector<Node> stack;

int count(){
	int cnt=0;
	for(int i=0;i<26;i++){
		if(m[i]==1) cnt++;
	}
	return cnt;
}

void dfs(){
	int size=stack.size();
	int ax = stack[size-1].x;
	int ay = stack[size-1].y;
	chk[ax][ay]=1;
	m[arr[ax][ay]-65]=1;
	//printf("(%d %d)\n",ax,ay);

	int tmp=count();
	if(tmax<tmp){
		tmax=tmp;
	}
	if(tmax==maxans) return;

	for(int i=0;i<4;i++){
		int tmpx = ax+dirx[i];
		int tmpy = ay+diry[i];
	//	printf("\t(%d %d)\n",tmpx,tmpy);
		if(tmpx<0 || tmpx>=r || tmpy<0 || tmpy>=c) continue;
		if(chk[tmpx][tmpy]==1) continue;
		if(m[arr[tmpx][tmpy]-65]==1) continue;
		chk[tmpx][tmpy]=1;
		m[arr[tmpx][tmpy]-65]=1;
		stack.push_back({tmpx,tmpy});
		dfs();
		chk[tmpx][tmpy]=0;
		m[arr[tmpx][tmpy]-65]=0;
		stack.erase(stack.begin()+size-1);
	}
	
	tmp=count();
	if(tmax<tmp){
		tmax=tmp;
	}
	
	return;
}

int main(){
	int Testcase;
	cin>>Testcase;
	for(int t=1;t<=Testcase;t++){
		cin>>r>>c;
		for(int i=0;i<r;i++){
			cin>>arr[i];
			for(int j=0;j<c;j++) chk[i][j]=0;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				alpha.push_back(arr[i][j]);
			}
		}
		sort(alpha.begin(),alpha.end());
		alpha.erase(unique(alpha.begin(),alpha.end()),alpha.end());
		maxans = alpha.size(); 
		for(int i=0;i<26;i++){
			m[i]=0;
		}

		tmax=0;
		stack.push_back({0,0});
		dfs();
		printf("#%d %d\n",t,tmax);
	}

}