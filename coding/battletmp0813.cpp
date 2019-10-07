#include <iostream>
#include <cstdio>
using namespace std;
int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	int n;
    
	for (test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d",&n);
        int tmp;
        register int tmax=0;
        register int arr[11];
        register int i;
        for(i=0;i<n;i++)
        {
        	scanf("%d",&tmp);
            if(tmp==0) continue;
            else if(tmp==1) tmax+=1;
            else if(tmax==0) tmax=tmp;
            else if(tmax==1) tmax+=tmp;
            else tmax*=tmp;
        }
        printf("#%d %d\n",test_case,tmax);
	}
	return 0;
}