#include <iostream>
#include <vector>

using namespace std;

int arr[100000];

vector<int> stack;
vector<char> ans;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		stack.clear();
		ans.clear();
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int ptr=0;
		int num=0;
		int chk=0;
		int cnt=0;
		
		while(1)
		{
			if(ans.size()==2*n)
				break;
			if(num > arr[ptr])
			{
				chk=1;
				break;
			}
			else if(num < arr[ptr])
			{
				for(int i=cnt+1;i<=arr[ptr];i++)
				{
					stack.push_back(i);	
					ans.push_back('+');
				}
				cnt=arr[ptr];
			}
			else
			{
				stack.pop_back();
				ans.push_back('-');
				ptr++;				
			}
			if(!stack.empty())
				num = stack.back();
			else num=cnt;
		}
		if(chk==0)
		{
			printf("#%d ",t);
			for(int i=0;i<ans.size();i++)
				printf("%c",ans[i]);
			printf("\n");
		}
		else
		{
			printf("#%d NO\n",t);
		}
	}
}