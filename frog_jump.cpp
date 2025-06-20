#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,s[20][20];
int si,sj,di,dj,ans=50000;
bool vis[20][20];

bool valid(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<n);
}

void dfs(int x,int y,int cnt)
{
    if(x==di && y==dj) 
    {
        ans = min(ans,cnt);
        return;
    }

    if(s[x][y]==1 && valid(x,y+1) && !vis[x][y+1] && s[x][y+1]==1) 
    {
        vis[x][y+1] = true;
        dfs(x,y+1,cnt);
    }
    if(s[x][y]==1 && valid(x,y-1) && !vis[x][y-1] && s[x][y-1]==1) 
    {
        vis[x][y-1] = true;
        dfs(x,y-1,cnt);
    }

    if(s[x][y]==1 && valid(x+1,y) && !vis[x+1][y]) 
    {
        vis[x+1][y] = true;
        dfs(x+1,y,cnt+1);
    }
    if(s[x][y]==1 && valid(x-1,y) && !vis[x-1][y]) 
    {
        vis[x-1][y] = true;
        dfs(x-1,y,cnt+1);
    }
    
    if(s[x][y]==0 && valid(x+1,y) && !vis[x+1][y]) 
    {
        vis[x+1][y] = true;
        dfs(x+1,y,cnt);
    }
    if(s[x][y]==0 && valid(x-1,y) && !vis[x-1][y]) 
    {
        vis[x-1][y] = true;
        dfs(x-1,y,cnt);
    }
}

void solve(int cs)
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> s[i][j];
    }
    cin >> si >> sj >> di >> dj;

    vis[si][sj] = true;
    dfs(si,sj,0);

    cout << ans << "\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
