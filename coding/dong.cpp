#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;
int n,x,m;
vector<pair< pair<int, int>, int> > arr;

int tmax;
vector<pair<int, vector<int> > > real;

int chk(int* ans){
	for(int i=0;i<arr.size();i++){
		int s,r,l;
		s = arr[i].first.first;
		r = arr[i].first.second;
		l = arr[i].second;
		int sum=0;
		for(int j=s;j<=r;j++){
			sum+=ans[j];
		}
		if(sum==l) continue;
		else return -1;
	}
	int total=0;
	for(int i=0;i<n;i++)
		total+=ans[i];
	return total;
}

void run(int* ans, int ptr){
	int tmp = chk(ans);
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
		printf("\n");
	if(tmp>tmax){
		tmax=tmp;
		vector<int> tmp;
		for(int i=0;i<n;i++){
			tmp.push_back(ans[i]);
		}
		real.push_back({tmax,tmp});
	}



	for(int i=ptr;i<n;i++){
		if(ans[i]<x){
			ans[i]++;
			run(ans,i+1);
			ans[i]--;
		}
	}

}

bool cmp(pair<int, vector<int> > a, pair<int, vector<int> > b){
	if(a.first>b.first) return a.first;
	else if(a.first <b.first) return b.first;
	else{
		for(int i=0;i<a.second.size();i++){
			if(a.second[i]>b.second[i]) return b.second[i];
			else if(a.second[i]<b.second[i]) return a.second[i];
		}
	}
	return true;
}

int main()
{
	int T;
	cin>>T;
	for(int test=1;test<=T;test++){
		tmax=-1;
		cin>>n>>x>>m;
		arr.clear();
		real.clear();
        int* ans;
        ans = (int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++) ans[i]=0;
		int l,r,s;
		for(int i=0;i<m;i++){
			cin>>l>>r>>s;
			arr.push_back({{l-1,r-1},s});
		}
		run(ans,n-1);


		printf("#%d ",test);
		sort(real.begin(),real.end(),cmp);
		if(real.empty()) {printf("-1\n"); continue;}
		
		for(int i=0;i<n;i++)
			printf("%d ",real[0].second[i]);
		printf("\n");
			
	}
}
