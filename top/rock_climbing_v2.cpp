#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

int n,m,ans;
int s[111][111];
bool possible,vis[111][111];

void dfs(int i,int j,int cur_max)
{
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(s[i][j]==0) return;
    if(vis[i][j]) return;

    if(s[i][j]==3)
    {
        ans = min(ans,cur_max);
        return;
    }   


    vis[i][j] = true;

    if(j-1>=0 && s[i][j-1]!=0 && !vis[i][j-1])
        dfs(i,j-1,cur_max);

    if(j+1<m && s[i][j+1]!=0 && !vis[i][j+1])
        dfs(i,j+1,cur_max);

    int up = i-1;

    while(up>=0)
    {
        if(s[up][j]!=0 && !vis[up][j])
            dfs(up,j,max(cur_max,abs(i-up)));
        up--;
    }

    int down = i+1;
    
    while(down<n)
    {
        if(s[down][j]!=0 && !vis[down][j])
            dfs(down,j,max(cur_max,abs(down-i)));

        down++;
    }
    
    vis[i][j] = false;
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
    dfs(n-1,0,0);

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