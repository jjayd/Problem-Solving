#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;


int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		vector<int> arr;

		int h;
		long sum=0;
		cin>>n>>m;
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			arr.push_back(tmp);
		}

		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());
		int left,right,pivot;
		left = arr[0];
		right = arr[n-1];
		pivot = arr[n/2];
		int result;
		vector<int> chk;

		while(1)
		{
			sum=0;
			if(find(chk.begin(),chk.end(),pivot) != chk.end()) break;
			else chk.push_back(pivot);
			printf("%d %d %d\n",pivot, left, right);
			for(int ptr=0;ptr<n;ptr++)
			{
				if(arr[ptr]-pivot<=0) break;
				sum+=arr[ptr]-pivot;
				if(sum>m) break;
			}

			if(sum>m) // pivot to left
			{
				//if()
				right=pivot;
				pivot=(right+left)/2; 
			}
			else if(sum<m) // pivot to right
			{
				left=pivot;
				pivot=(right+left)/2;
			}
			else if(sum==m) // answer
			{
				h=pivot;
				break;
			}

			if(left==right)
			{
				if(sum>m) pivot++;
				else if(sum<m) pivot--;
			}


		}

		printf("#%d %d\n",i,pivot);

	}
}