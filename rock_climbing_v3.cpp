#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;


int n,m,ans;
bool is_ok = false,vis[11][11];

void back(int i,int j,vector<vector<int>> &s,vector<vector<int>>& dp)
{
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty())
    {
        auto [x,y] = q.front();q.pop();
        if(s[x][y]==3)
        {
            ans = min(ans,dp[x][y]);
        }

        if(y+1<m && s[x][y+1]!=0 && dp[x][y]<dp[x][y+1]) 
        {
            dp[x][y+1] = dp[x][y];
            q.push({x,y+1});
        }

        if(y-1>=0 && s[x][y-1]!=0 && dp[x][y]<dp[x][y-1]) 
        {
            dp[x][y-1] = dp[x][y];
            q.push({x,y-1});
        }

        for(int p=0;p<n;p++)
        {
            if(p==x || s[p][y]==0) continue;
            int dis = max(abs(p-x),dp[x][y]);
            if(dis<dp[p][y])
            {
                dp[p][y] = dis;
                q.push({p,y});
            }
        }
    }
}

void solve(int cs)
{
    cin >> n >> m;
    vector<vector<int>> s(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> s[i][j];
        }
    }

    if(s[n-1][0]==0)
    {
        cout << 0 << endl;
        return;
    }

    ans = 999;
    vector<vector<int>> dp(n,vector<int>(m,n+1));

    dp[n-1][0] = 0;
    back(n-1,0,s,dp);

    cout << ans << endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
