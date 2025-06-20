#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int X[4] = {1,-1,0,0}, Y[4] = {0,0,1,-1};


void solve(int cs)
{
    int n,m;
    cin >> m >> n;
    int s[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin >> s[i][j];
    }
    int si,sj;
    cin >> sj >> si;

    si--;sj--;

    bool vis[n][m];
    memset(vis,false,sizeof(vis));

    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    s[si][sj] = 1;
    int ans = 0;

    while(!q.empty())
    {
        ans++;
        int sz = q.size();
        // cout << "size now -> " << sz << endl;
        while(sz--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            vis[x][y] = true;

            // cout << "ans" << ans << ' ' << x << ' ' << y << endl;

            for(int i=0;i<4;i++)
            {
                int nex = x+X[i], ney = y+Y[i];
                if(nex<0 || nex>=n || ney<0 || ney>=m) continue;
                if(vis[nex][ney]) continue;
                if(s[nex][ney]!=1) continue;

                q.push({nex,ney});
            }
        }
    }

    cout << "Case #" << cs << "\n";
    cout << ans << endl;

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
