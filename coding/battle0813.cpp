#include<iostream>
#include <vector>
#include <algorithm>
int n;
using namespace std;

vector<int> arr;
int tmax;

void run(int cnt,int num)
{
	if(cnt==arr.size()-1)
	{
		if(num>tmax) tmax=num;
		return;
	}
	num+=arr[cnt+1];
	run(cnt+1,num);
	num-=arr[cnt+1];
	num*=arr[cnt+1];
	run(cnt+1,num);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        int tmp;
        tmax=0;
        arr.clear();
        for(int i=0;i<n;i++)
        {
        	cin>>tmp;
        	if(tmp!=0) arr.push_back(tmp);
           
        }
        if(arr.empty()) printf("#%d 0\n",test_case);
        else run(0,arr[0]);

        printf("#%d %d\n",test_case,tmax);

	}
	return 0;
}