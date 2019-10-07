#include <iostream>
#include <vector>
using namespace std;

int tmax=0;
int n;
int t[20];
int p[20];

vector<int> arr;

int cal(){
	int sum=0;
	for(int i=0;i<arr.size();i++){
		sum+=p[arr[i]];
	}
	return sum;
}

void run(int ptr){
	int tmp=cal();
	if(tmp>tmax){
		tmax=tmp;
	}

	for(int i=ptr;i<n;i++){
		if(i+t[i]<=n){
			arr.push_back(i);
			run(i+t[i]);
			arr.pop_back();
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i]>>p[i];
	}
	for(int i=0;i<n;i++)
		run(0);
	printf("%d\n",tmax);
}