#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int makeint(string a){
	int size=a.size();
	int ans=0;
	for(int i=0;i<size;i++){
		if(a[size-i-1]>=65) a[size-i-1]-=55;
		else a[size-i-1]-=48;
		ans+=pow(16,i)*int(a[size-i-1]);
	}
	cout<<ans<<endl;

	return ans;
}

int main(){
	int n,t,k;
	string tmp;
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n>>k;
		cin>>tmp;
		vector<int> arr;
		string change="";
		for(int i=0;i<n;i++){
			for(int j=0;j<n/4;j++){
				cout<<tmp[(i+j)%n];
				change+=tmp[(i+j)%n];
			}
			arr.push_back(makeint(change));
			change.clear();
		}
		sort(arr.begin(),arr.end());
		arr.erase(unique(arr.begin(),arr.end()),arr.end());
		reverse(arr.begin(),arr.end());
		cout<<"#"<<T<<" "<<arr[k-1]<<endl;
	}
}