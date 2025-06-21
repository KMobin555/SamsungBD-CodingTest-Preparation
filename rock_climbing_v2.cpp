#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;


int n,m;
bool is_ok = false,vis[11][11];

void back(int i,int j,vector<vector<int>> &s,int l)
{
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(vis[i][j]) return;

    vis[i][j] = true;
    if(s[i][j]==3)
    {
        is_ok = true;
        return;
    }

    if(j+1<m && s[i][j+1]!=0 && !vis[i][j+1]) back(i,j+1,s,l);
    if(j-1>=0 && s[i][j-1]!=0 && !vis[i][j-1]) back(i,j-1,s,l);

    for(int p=0;p<=l;p++)
    {
        if(i-p>=0 && s[i-p][j]!=0 && !vis[i-p][j]) back(i-p,j,s,l);
        if(i+p<n && s[i+p][j]!=0 && !vis[i+p][j]) back(i+p,j,s,l);
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


    for(int l=0;l<=n;l++)
    {
        is_ok = false;
        memset(vis,false,sizeof(vis));
        back(n-1,0,s,l);
        if(is_ok) 
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
