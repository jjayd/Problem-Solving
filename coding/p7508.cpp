#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m;
		int tmp;
		vector<int> a,b;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			a.push_back(tmp);
		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>tmp;
			b.push_back(tmp);
		}
		
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);

		if(a.front()<b.front())
		{
			printf("#%d -1\n",t);
			continue;
		}



		vector<int> can;
		int cnt;

		for(int i=0;i<a.size();i++)
		{
			cnt=0;
			for(int j=0;j<b.size();j++)
			{
				if(a[i]>=b[j])
				{
					cnt = b.size()-j;
					break;
				}
			}
			can.push_back(cnt);
		}

		if(a.size()==1)
		{
			printf("#%d %d\n",t,can[0]);
			continue;
		}

		for(int i=0;i<can.size();i++)
			printf("%d ",can[i]);

		cnt=0;

		while(1)
		{
			int minus = can[0]-can[1];
			printf("can[0]:%d can[1]:%d , minus: %d\n",can[0],can[1],minus);
			cnt++;
			if(can[1]<=0) break;

			for(int i=0;i<can.size();i++)
			{
				can[i]=can[i]-minus;
			}


		}

		/*

		for(int i=0;i<can.size();i++)
		{
			int max = can[i]; // left maximum
			int help=i; // # of zeros
			if(max==0) continue;
			for(int j=i;j<can.size();j++)
				can[j] -= (max+help);
			for(int j=i+1;j<can.size();j++)
			{
				if(can[j]<0)
				{
					int tmp=j+1;
					int minus = can[j];
					while(1)
					{
						if(can[tmp]>0)
						{
							if(can[tmp]>=minus)
							{
								can[tmp] += minus;
								minus=0;
								break;
							}
							else if(can[tmp]<minus)
							{
								minus += can[tmp];
								can[tmp]=0;
							}

						} 
					}
				}
			}
		}
		

		int cnt=0;

		while(!b.empty())
		{
			for(int i=0;i<a.size();i++)
			{
				int ptr=0;
				if(b.empty()) break;
				while(1)
				{
					if(ptr>=b.size()) break;
					if(a[i] >= b[ptr])
					{
						b.erase(b.begin()+ptr);
						break;
					}
					else ptr++;
				}
			}
			cnt++;
		}
		*/
		printf("#%d %d\n",t,cnt);
	}
}
