#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,a,b;
		cin>>n>>a>>b;
		vector<int> arr;
		for(int i=0;i<n;i++)
		{
			int tmp;
			cin>>tmp;
			arr.push_back(tmp);
		}
		int time=0;
		printf("#%d ",t);
		while(!arr.empty())
		{
		//	printf("\ntime: %d arr[0]:%d\n",time,arr[0]);
			int cnt=0;
			
			for(int i=0;i<arr.size();i++)
			{
				if(arr[i]<=time) cnt++;
				else break;
			}
		//	printf("cnt:%d\n",cnt);
			int tmpcnt;
			if(cnt%2==0) tmpcnt=cnt/2;
			else tmpcnt=cnt/2+1;
			if(cnt>=a)
			{
				for(int i=0;i<tmpcnt;i++)
					printf("%d ",time);
				arr.erase(arr.begin(),arr.begin()+tmpcnt);

			}
			else if(arr[0]+b==time)
			{
				if(cnt==1)
				{
					printf("%d ",time);
					arr.erase(arr.begin(),arr.begin()+1);
				}
				else
				{	
					for(int i=0;i<tmpcnt;i++)
						printf("%d ",time);
					arr.erase(arr.begin(),arr.begin()+tmpcnt);
				}
				
			}
			time++;
		}
		printf("\n");
	}
}