#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
 
using namespace std;
 
typedef pair<int, int> pii;
 
int n, m;
int arr[10];
 
bool visit[10];
vector<int> vc;
 
void dfs(int cnt)
{
    if (vc.size() == m)
    {
        for(int i=0;i<vc.size();i++) printf("%d ",vc[i]);
        printf("\n");
        return;
    }
 
    for (int i = cnt; i < n; i++)
    {
        if(!visit[i])
        {
            vc.push_back(arr[i]);
            visit[i] = true;
            dfs(i + 1);
            visit[i] = false;
            vc.pop_back(); 
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
 
        arr[i] = val;
    }
    sort(arr, arr + n);
    dfs(0);
 
    return 0;
}
 

