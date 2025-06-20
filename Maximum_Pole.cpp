#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n,ans;
vector<int> s(200);
bool vis[200];

void dfs(int left, int right)
{
    if(left==right) 
    {
        ans = max(ans,left);
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            dfs(left+s[i],right);
            dfs(left,right+s[i]);
            vis[i] = false;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    memset(vis,false,sizeof(vis));

    ans = 0;
    dfs(0,0);

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
