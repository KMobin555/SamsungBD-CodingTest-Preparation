#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

int ans,n;
bool vis[111];
vector<pair<int,int>> s(22);

int dist(int i,int j)
{
    return abs(s[i].first-s[j].first)+abs(s[i].second-s[j].second);
}

void dfs(int u,int cnt,int total)
{
    if(cnt==n)
    {
        ans = min(ans,total+dist(u,n+1));
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            dfs(i,cnt+1,total+dist(u,i));
            vis[i] = false;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    s.clear();    

    cin >> s[n+1].first >> s[n+1].second >> s[0].first >> s[0].second;
    for(int i=1;i<=n;i++) cin >> s[i].first >> s[i].second;

    
    ans = INT_MAX;
    memset(vis,false,sizeof(vis));

    dfs(0,0,0);

    cout << "# " << cs << " " << ans << endl;
}

void io()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

int main()
{

    // io();
    
    int t = 10, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
