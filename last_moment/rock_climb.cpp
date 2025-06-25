#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int s[111][111],dp[111][111];
int n,m,ans;

void bfs(int xx,int xy)
{
    queue<pair<int,int>> q;
    q.push({xx,xy});

    while(!q.empty())
    {
        auto [x,y] = q.front();q.pop();

        if(s[x][y]==3)
        {
            ans = min(ans,dp[x][y]);
            // continue;
        }

        if(y+1<m && s[x][y+1]!=0 && dp[x][y+1]>dp[x][y])
        {
            dp[x][y+1] = dp[x][y];
            q.push({x,y+1});
        }
        if(y-1>=0 && s[x][y-1]!=0 && dp[x][y-1]>dp[x][y])
        {
            dp[x][y-1] = dp[x][y];
            q.push({x,y-1});
        }

        for(int i=0;i<n;i++)
        {
            if(i==x || s[i][y]==0) continue;

            int dist = max(abs(i-x),dp[x][y]);
            if(dp[i][y]>dist)
            {
                dp[i][y] = dist;
                q.push({i,y});
            }
        }
    }
}
void solve(int cs)
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> s[i][j];
        }
    }

    memset(dp,n-1,sizeof(dp));

    ans = 2e9;

    dp[n-1][0] = 0;
    bfs(n-1,0);

    cout << ans << endl;
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
    
    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
