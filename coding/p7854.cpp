#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans;

vector<int> m;

int chk(int n)
{
	int cnt=0;
	
	int chk=0;
	for(int j=1;j<5;j++)
	{
		string s1 = to_string(j);
		string s2 = to_string(n);

		s1.append(s2);
		
		if(stoll(s1)%n!=0)
		{
			chk=1;
			break;
		}
	}
	if(chk==0)
	{
		cnt++;
	}

	return cnt;
		
}

void run(int tmp)
{
	vector<int>::iterator iter;
	iter=find(m.begin(), m.end(), tmp);
	if(iter!=m.end()) return;
	m.push_back(tmp);
	if(tmp<=n)
	{
		ans+=chk(tmp);
	}
	else return;

	run(tmp*2);
	run(tmp*5);

	return;
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		m.clear();
		cin>>n;
		ans=0;
		run(1);
		printf("#%d %d\n",i,ans);
	}
}