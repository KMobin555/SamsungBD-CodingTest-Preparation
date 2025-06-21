#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;


int n,m,ans;
bool is_ok = false,vis[11][11];

void back(int i,int j,vector<vector<int>> &s,int max_till_now)
{
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(vis[i][j]) return;

    if(s[i][j]==3) 
    {
        ans=min(ans,max_till_now);
        return;
    }

    vis[i][j] = true;

    if(j+1<m && s[i][j+1]!=0 && !vis[i][j+1]) back(i,j+1,s,max_till_now);
    if(j-1>=0 && s[i][j-1]!=0 && !vis[i][j-1]) back(i,j-1,s,max_till_now);

    int up = i-1;
    while(up>=0)
    {
        if(s[up][j]!=0 && !vis[up][j]) back(up,j,s,max(max_till_now,abs(up-i)));
        up--;
    }
    int down = i+1;
    while(down<n)
    {
        if(s[down][j]!=0 && !vis[down][j]) back(down,j,s,max(max_till_now,abs(down-i)));
        down++;
    }

    vis[i][j] = false;
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

    ans = 11;
    back(n-1,0,s,0);

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
