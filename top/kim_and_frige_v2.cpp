#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int ans,n;
bool vis[111];
vector<pair<int,int>> s(22);
int dp[1<<12][22];

int dist(int i,int j)
{
    return abs(s[i].first-s[j].first)+abs(s[i].second-s[j].second);
}

int dfs(int u,int mask)
{
    if(mask == ((1<<n)-1))
    {
        return dist(u,n+1);
    }

    int &res = dp[mask][u];
    if(res!=-1) return res;

    res = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        if(mask & (1<<(i-1))) continue;

        res = min(res,dfs(i,mask|(1<<(i-1))) + dist(u,i));        
    }
    return res;
}

void solve(int cs)
{
    cin >> n;
    s.clear();    

    cin >> s[n+1].first >> s[n+1].second >> s[0].first >> s[0].second;
    for(int i=1;i<=n;i++) cin >> s[i].first >> s[i].second;

    
    ans = INT_MAX;
    memset(dp,-1,sizeof(dp));

    ans = dfs(0,0);

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
