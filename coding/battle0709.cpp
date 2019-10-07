#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> ans;
int n;
int until;
void find(vector<int> tmp)
{
	if(tmp.size()==until+2) return;
	//printf("find!\n");
	//for(int i=0;i<tmp.size();i++)
//		printf("%d ",tmp[i]);
//	printf("\n");
	vector<int> go;
	go.push_back(-1);
	for(int i=1;i<tmp.size()-1;i++)
	{
		int left = (tmp[i]+tmp[i-1])/2;
		int right = (tmp[i]+tmp[i+1])/2;
		go.push_back(left);
		go.push_back(tmp[i]);
		go.push_back(right);
		ans.push_back(left);
		ans.push_back(right); 
	}
	go.erase(unique(go.begin(),go.end()),go.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	go.push_back(until);
	find(go);
}

int upto2n_1(int n)
{
	int a=1;
	for(int i=0;i<n;i++)
	{
		a=a*2;
	}
	return a-1;
}

int upto2n(int n)
{
	int a=1;
	for(int i=0;i<n;i++)
	{
		a=a*2;
	}
	return a;
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
		until=upto2n_1(n);
		for(int j=0;j<until;j++)
		{
			int tmp;
			cin>>tmp;
			arr.push_back(tmp);		
		}
		
		vector<int> tmp;
		tmp.push_back(-1);
		tmp.push_back(until/2);
		tmp.push_back(until);
	
		ans.push_back(until/2);
		find(tmp);

		int pr=0;

		printf("#%d ",i);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<upto2n(j);k++)
			{
				printf("%d ",arr[ans[pr]]);
				pr++;
			}
			printf("\n");
		}
	}
}

//n=15

//-1 .. 0 1 2 (3) 4 5 6 (7) 8 9 10 (11) 12 13 14 .. 15
 //-1 0 [1] 2 (3) 4 [5] 6 7


















