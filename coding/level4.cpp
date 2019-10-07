#include<vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;

int solution(vector<vector<int> > maps)
{
	int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    vector<pair<int,pair<int,int> > > queue;
    vector< vector<vector<int> > > checking;
    
    vector<vector<int> > tmp;
    for(int i=0;i<n;i++){
        vector<int> ttmp;
        for(int j=0;j<m;j++) ttmp.push_back(0);
        tmp.push_back(ttmp);
    }
    checking.push_back(tmp);
    queue.push_back({1,{0,0}});
    int dirx[4] = {1,0,-1,0};
    int diry[4] = {0,1,0,-1};
    printf("start\n");
    
    while(!queue.empty()){
        int cnt = queue[0].first;
        int x = queue[0].second.first;
        int y = queue[0].second.second;
        printf("{%d %d}, %d\n",x,y,cnt);
        vector<vector<int> > chk = checking[0];
        checking.erase(checking.begin());
        queue.erase(queue.begin());
        for(int i=0;i<4;i++){
            int tmpx = x + dirx[i];
            int tmpy = y + diry[i];
            
            if(tmpx<0 || tmpy<0 || tmpx>=n || tmpy>=m) continue;
            if(maps[tmpx][tmpy]==0) continue;
            if(chk[tmpx][tmpy]==1) continue;
            if(tmpx==n && tmpy==m) return cnt+1;
            
            queue.push_back({cnt+1,{tmpx,tmpy}});
            chk[tmpx][tmpy]=1;
            checking.push_back(chk);
        }
    }
    
    return -1;
    
}

int main(){
    vector<vector<int> > test;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    test.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(1);
    test.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    test.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(1);
    test.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(1);
    test.push_back(tmp);
    tmp.clear();
    int ans = solution(test);
    printf("ans:%d\n",ans);
}