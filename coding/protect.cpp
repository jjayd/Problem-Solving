#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int d,w,k;
int arr[13][20];
int tmin;
int chk[15];
int got=0;

void test(int mode) //possible?
{
	int a, b;
    bool flag;
    if(mode==0) {
        for(int i=0; i<w; i++) {
            a = 0;
            b = 0;
            flag = false;
            for(int j=0; j<d; j++) {
                if(arr[j][i] == 0 || chk[j]) {
                    a++;
                    b=0;
                } else {
                    b++;
                    a=0;
                }
                if(a==k || b==k) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return;
          
        }
    } 
    else {
        for(int i=0; i<w; i++) {
            a = 0;
            b = 0;
            flag = false;
            for(int j=0; j<d; j++) {
                if(arr[j][i] == 1 || chk[j]) {
                    b++;
                    a=0;
                } else {
                    a++;
                    b=0;
                }
                if(a==k || b==k) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return ;
        }
    }

	got=1;
	return;
}


void dfs(int x, int cnt, int ptr) //x 개 줄을 고르면 된다! 
{
	if(cnt==x)
	{
		test(0);
		test(1);
		return;	
	}
	for(int i=ptr;i<d;i++)
	{
		if(chk[i]==0)
		{
			chk[i]=1;
			dfs(x,cnt+1,i+1);
			chk[i]=0;
		}
	}
	
}

void solve()
{
	for(int i=0;i<=k;i++)
	{
		got=0;
		

		for(int j=0;j<d;j++) chk[j]=0;
	
		dfs(i,0,0);
		if(got==1)
		{
		 	tmin=i;
		 	return;
		}

	}
}

int main()
{
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		cin>>d>>w>>k;
		tmin=99999999;
		for(int i=0;i<d;i++)
		{
			for(int j=0;j<w;j++)
				cin>>arr[i][j];
		}

		if(k==1) 
		{
			printf("#%d %d\n",p,0);
			continue;
		}
		solve();

		printf("#%d %d\n",p,tmin);

	}
}