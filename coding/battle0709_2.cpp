#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int ans,n;
int arr[200][200];
vector<pair<string,string> > namepair;
vector<string> names;
vector<pair<string, vector<string> > > m;
vector<int> p1,p2;


bool cmp(const pair<string,vector<string> > &a, const pair<string, vector<string> > &b)
{
	if(a.second.size() > b.second.size())
		return true;
	else return false;
}


void per()
{
	int total;
	sort(names.begin(),names.end(),less<string>());
	names.erase(unique(names.begin(),names.end()),names.end());

	sort(namepair.begin(),namepair.end());
	for(int i=0;i<namepair.size();i++)
	{
		int j;
		for(j=0;j<m.size();j++)
		{
			if(m[j].first==namepair[i].first) break;
		}
		if(j==m.size())
		{
			vector<string> tmp;
			tmp.push_back(namepair[i].second);
			m.push_back(make_pair(namepair[i].first,tmp));
		}
		else
		{
			vector<string> tmp = m[j].second;
			tmp.push_back(namepair[i].second);
			m[j].second = tmp;
		}
		for(j=0;j<m.size();j++)
		{
			if(m[j].first==namepair[i].second) break;
		}
		if(j==m.size())
		{
			vector<string> tmp;
			tmp.push_back(namepair[i].first);
			m.push_back(make_pair(namepair[i].second,tmp));
		}
		else
		{
			vector<string> tmp = m[j].second;
			tmp.push_back(namepair[i].first);
			m[j].second = tmp;
		}
	}

	sort(m.begin(),m.end(),cmp);

	for(int i=0;i<m.size();i++)
		cout<<m[i].first<<": "<<m[i].second.size()<<endl;
	printf("\nname idx\n");

	for(int i=0;i<names.size();i++)
		cout<<names[i]<< " ";
	cout<<endl;

	
	total = m.size(); // the size of name
	int ptr=-1;
	ans=0;
	int chk[300];
	for(int i=0;i<300;i++)
		chk[i]=-1;
	for(int i=0;i<total;i++)
	{
		vector<string> tmp = m[i].second;
		int idx1,idx2;

		for(idx1=0;idx1<names.size();idx1++)
		{
			if(names[idx1]==m[idx1].first) break;
		}
		if(ptr==-1)
		{
			chk[idx1]=1;
			ptr=1;
		}
		if(chk[idx1]!=-1) continue;
	

		cout<<m[i].first<<idx1<<endl;
		vector<string> v;

		for(int j=0;j<tmp.size();j++)
		{
			for(idx2=0;idx2<names.size();idx2++)
			{
				if(names[idx2]==tmp[idx2]) break;
			}
			cout<<tmp[j]<<idx2<<endl;

			if(ptr==1)
			{
				vector<int>:: iterator it = std::find(p1.begin(), p1.end(), idx2);
				if(it==p1.end()) p2.push_back(idx2);
				else return;
				v.push_back(idx2);
			}
			else
			{
				vector<int>:: iterator it = std::find(p2.begin(), p2.end(), idx2);
				if(it==p2.end()) p1.push_back(idx2);
				else return;
				v.push_back(idx2);
			}
		}
		ptr = ptr%2+1;

		rota(v,ptr);
	}

	ans=1;
	return;

}


int main()
{
	int T;

	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		names.clear();
		m.clear();
		namepair.clear();
		p1.clear();
		p2.clear();
		for(int j=0;j<n;j++)
		{
			string a,b;
			cin >> a;
			cin >> b;
			namepair.push_back(make_pair(a,b));
			names.push_back(a);
			names.push_back(b);
		}
		per();
		if(ans==1) printf("#%d Yes\n",i);
		else printf("#%d No\n",i);

		printf("-----------------\n\n\n");
	}
}

