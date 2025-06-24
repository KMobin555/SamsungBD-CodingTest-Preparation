#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>

using namespace std;
int n,m,ans;
int s[11][11];
bool vis[11][11];
bool is_possi;

void dfs(int i,int j,int cnt)
{
    if(i<0 || i>=n) return;
    if(j<0 || j>=m) return;
    if(vis[i][j]) return;

    vis[i][j] = true;
    if(s[i][j]==3)
    {
        is_possi = true;
        return;
    }

    if(j+1<m && s[i][j+1]!=0 && !vis[i][j+1]) dfs(i,j+1,cnt);

    if(j-1>=0 && s[i][j-1]!=0 && !vis[i][j-1]) dfs(i,j-1,cnt);


    for(int k=1;k<=cnt;k++)
    {
        int nx = i+k;
        if(nx<n && s[nx][j]!=0 && !vis[nx][j]) 
            dfs(nx,j,cnt);
        
        nx = i-k;
        if(nx>=0 && s[nx][j]!=0 && !vis[nx][j])   
            dfs(nx,j,cnt);
    }
}

void solve(int cs)
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin >> s[i][j];
    }

    ans = INT_MAX;
    for(int l=0;l<=n;l++)
    {
        is_possi = false;
        memset(vis,false,sizeof(vis));
        dfs(n-1,0,l);
        if(is_possi)
        {
            cout << l << endl;
            return;
        }
    }
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
