#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
    int* ans;
    ans = (int*)malloc(sizeof(int)*T);
	int n;
    int tmp;
    int i;
    int tmax=0;

	for (test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d",&n);
        tmax=0;
        for(i=0;i<n;i++)
        {
        	scanf("%d",&tmp);
            if(tmp==0) continue;
            else if(tmp==1) tmax+=1;
            else if(tmax==0) tmax=tmp;
            else if(tmax==1) tmax+=tmp;
            else tmax*=tmp;
        }
        ans[test_case-1] = tmax;

        
	}
    for(test_case = 1; test_case<T; test_case++)
        printf("#%d %d\n",test_case,ans[test_case-1]);
	return 0;
}