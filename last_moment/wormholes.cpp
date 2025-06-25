#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
using namespace std;

int n,w[111][5],y[111];
bool vis[111];
int sx,sy,dx,dy,ans;


int dist(int sx,int sy,int dx,int dy)
{
    return abs(sx-dx)+abs(sy-dy);
}

void dfs(int sx,int sy,int dx,int dy,int cost)
{
    ans = min(ans,cost+dist(sx,sy,dx,dy));

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;

            int tem = cost+dist(sx,sy,w[i][0],w[i][1])+w[i][4];
            dfs(w[i][2],w[i][3],dx,dy,tem);

            tem = cost+dist(sx,sy,w[i][2],w[i][3])+w[i][4];
            dfs(w[i][0],w[i][1],dx,dy,tem);

            vis[i] = false;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    cin >> sx >> sy >> dx >> dy;
    for(int i=1;i<=n;i++)
    {
        cin >> w[i][0] >> w[i][1] >> w[i][2] >> w[i][3] >> w[i][4];
    }

    memset(vis,false,sizeof(vis));

    ans = INT_MAX;

    dfs(sx,sy,dx,dy,0);

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
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
