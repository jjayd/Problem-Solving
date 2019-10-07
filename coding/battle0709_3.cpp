#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<int> arr, ans;

void act()
{
	sort(arr.begin(),arr.end());

	vector<int> tmp;
	tmp=arr;
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

	int cnt = tmp.size();
	if(cnt==2)
	{
		if(tmp[0]+1==tmp[1])
		{
			reverse(arr.begin(),arr.end());
			ans=arr;
		}
		else
			ans = arr;
		return;
	}

	int cur = arr[0];

	ans.push_back(cur);
	arr.erase(arr.begin());

	int chk=0;

	while(1)
	{
/*		printf("ans: ");
		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");

		printf("arr: ");
		for(int i=0;i<arr.size();i++)
			printf("%d ",arr[i]);
		printf("\n");
*/
		int ptr = 0;
		while(1)
		{
			if(ptr==arr.size())
			{
				chk=1;
				break;
			}
			if(arr[ptr]!=cur+1) break;
			ptr++;
		}
		if(chk==1)
		{
			vector<int> tmp;
			int last = ans[ans.size()-1];
			ans.erase(ans.end()-1);
			tmp.push_back(last);
			while(1)
			{
				int nop = ans.size()-1;
				if(ans[nop]==last)
				{
					tmp.push_back(last);
					ans.erase(ans.end()-1);
				}
				else break;

			}			

			for(int i=0;i<arr.size();i++)
				ans.push_back(arr[i]);
			
			for(int i=0;i<tmp.size();i++)
				ans.push_back(tmp[i]);
			return;

		}
		cur = arr[ptr];
		ans.push_back(arr[ptr]);
		arr.erase(arr.begin()+ptr);
		if(arr.empty()) return;
	}
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		arr.clear();
		ans.clear();
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			arr.push_back(tmp);
		}
		act();
		printf("#%d ",i);
		for(int j=0;j<n;j++)
			printf("%d ",ans[j]);
		printf("\n");		
	}
}

