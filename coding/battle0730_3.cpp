#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long ans;

void run(int n)
{
	if(n<=4)
	{
		if(n==2) ans=1;
		if(n==3) ans=3;
		if(n==4) ans=6;
		return;
	}


//	n*(n-1C2+....n-1Cn-3)/2 // 2^(n-1)-n
//	nC2*(n-2C2 + ... n-2Cn-4)/2 //n*(n-1)/2 * (2^(n-2)-n+1)
	ans = (n*n-n+4)/8*pow(2,n)-(n*n*n-2*n*n+3*n)/2;
}

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		run(n);
		printf("#%d %llu\n",t,ans%1000000007);
	}
}