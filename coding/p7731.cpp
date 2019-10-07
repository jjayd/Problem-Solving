#include <iostream>
#include <string>
using namespace std;




int chk(int left, int ptr, int right)
{
	int cases=-1;
	int sum = left+ptr+right;
	if(left==ptr && ptr==right) cases=0;
	else if(sum==219) cases=0;
	else if(sum==235 || sum==208 || sum==214) cases=1;
	else cases=2;

	return cases;
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n,k;
		int r,g,b;
		r=0;
		g=0;
		b=0;
		string dot,tmp;
		cin>>n>>k;
		cin>>dot;

		tmp=dot;

		for(int j=0;j<k;j++)
		{
			for(int ptr=0;ptr<n;ptr++)
			{
				int left,right,center;

				center = dot[ptr];
				if(ptr==0) left = dot[n-1];
				else left = dot[ptr-1];
				if(ptr==n-1) right = dot[0];
				else right = dot[ptr+1];

	//			printf("%c: %d %c: %d %c: %d\n",left,left,right,right,center,center);

				int cases = chk(left,center,right);
				if(cases==0) tmp[ptr]='B';
				else if(cases==1) tmp[ptr]='R';
				else tmp[ptr]='G';
			}
			dot=tmp;
		}


		for(int j=0;j<n;j++)
		{
			if(dot[j]=='R') r++;
			else if(dot[j]=='G') g++;
			else b++;
		}


		printf("#%d %d %d %d\n",i,r,g,b);

	}
}