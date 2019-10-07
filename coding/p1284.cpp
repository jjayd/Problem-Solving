#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int p,q,r,s,w;
int aans;
int bans;


void run()
{
	aans=p*w;
	if(w<=r) bans=q;
	else bans=q+(w-r)*s;

}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>p>>q>>r>>s>>w;
		
		run();
		if(aans>bans)	printf("#%d %d\n",i,bans);
		else printf("#%d %d\n",i,aans);
	}
}