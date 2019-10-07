#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> arr;
	int max=0;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
		if(tmp>max) max=tmp;
	}

	int left=0,right=max;
	int cur,sum=0;

	while(left<right){
		cur=(left+right)/2;
		sum=0;
		for(int i=0;i<n;i++){
			if(arr[i]-cur>0) sum+=arr[i]-cur;
		}
		if(sum==m) break;
		if(sum>m) left=cur;
		else right=cur;
	}
	printf("%d\n",cur);
}