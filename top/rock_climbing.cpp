#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m;
int s[111][111];
bool possible,vis[111][111];

void dfs(int i,int j,int l)
{
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(s[i][j]==0) return;
    if(vis[i][j]) return;

    vis[i][j] = true;
    if(s[i][j]==3)
    {
        possible = true;
        return;
    }   

    if(j-1>=0 && s[i][j-1]!=0 && !vis[i][j-1])
        dfs(i,j-1,l);

    if(j+1<m && s[i][j+1]!=0 && !vis[i][j+1])
        dfs(i,j+1,l);

    for(int p=1;p<=l;p++)
    {
        if(i-p>=0 && s[i-p][j]!=0 && !vis[i-p][j])
            dfs(i-p,j,l);
        
        if(i+p<n && s[i+p][j]!=0 && !vis[i+p][j])
            dfs(i+p,j,l);
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

    for(int i=0;i<n;i++)
    {
        possible = false;
        memset(vis,false,sizeof(vis));
        dfs(n-1,0,i);
        if(possible)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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