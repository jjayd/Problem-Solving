#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int tmin;

int ans[10];

int run(int x, int y){
	int sum=abs(x)+abs(y);
	if(sum==0) return 0;
	int cnt=1;
	while(1){
		if(sum>cnt){
			sum-=cnt;
			cnt++;
		}else if(sum==cnt) return cnt;
		else{
			if(sum%2==cnt%2) return cnt;
			else{
				if(sum%2==1) return cnt+1;
				else return cnt+2;
			}
		}
	}
}

int sum(int x){
	return x*(x+1)/2;
}

int main(){
	int testcase;
	cin>>testcase;
	for(int t=1;t<=testcase;t++){
		cin>>n;
		int tmpx,tmpy;
		for(int i=0;i<n;i++){
			cin>>tmpx>>tmpy;
			ans[i] = run(tmpx,tmpy);
		}
		tmin=ans[0];
		int chk=0;
		for(int i=0;i<n-1;i++){
			if(sum(ans[i])%2!=sum(ans[i+1])%2){
				printf("#%d %d\n",t,-1);
				chk=1;
				break;
			}
			if(tmin<ans[i+1]) tmin=ans[i+1];
		}
		if(chk==0)	printf("#%d %d\n",t,tmin);
	}
}