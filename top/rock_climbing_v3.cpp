#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<queue>
using namespace std;

int n,m,ans;
int s[111][111],dp[111][111];
bool possible,vis[111][111];

void dfs(int i,int j)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    

    while(!q.empty())
    {
        auto [x,y] = q.front();q.pop();

        if(s[x][y]==3) {
            ans = min(ans,dp[x][y]);
        }
        

        if(y-1>=0 && s[x][y-1]!=0 && dp[x][y]<dp[x][y-1])
        {
            dp[x][y-1] = dp[x][y];
            q.push({x,y-1});
        }

        if(y+1<m && s[x][y+1]!=0 && dp[x][y]<dp[x][y+1])
        {
            dp[x][y+1] = dp[x][y];
            q.push({x,y+1});
        }


        for(int i=0;i<n;i++)
        {
            if(i==x || s[i][y]==0) continue;

            int dis = max(abs(i-x),dp[x][y]);
            if(dis < dp[i][y])
            {
                dp[i][y] = dis;
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

    ans = INT_MAX;
    memset(vis,false,sizeof(vis));
    memset(dp,n-1,sizeof(dp));

    dp[n-1][0]=0;
    dfs(n-1,0);

    cout << ans << endl;
}

void io()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    // io();

    int t=1,cs=1;
    // cin >> t;

    while(t--)
        solve(cs++);
}