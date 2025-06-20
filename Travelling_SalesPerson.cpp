#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>

using namespace std;


int s[15][15],n,ans;
bool vis[15];

void back(vector<int> &v)
{
    if(v.size()==n-1)
    {
        int sum = 0, last=0;
        for(int x:v)
        {
            sum+=s[last][x];
            last = x;
        }
        sum+=s[last][0];
        ans=min(ans,sum);
        return;
    }
    for(int i=1;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            v.push_back(i);
            back(v);
            v.pop_back();
            vis[i] = false;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> s[i][j];
    }

    ans = INT_MAX;
    vector<int> v;
    memset(vis,false,sizeof(vis));
    back(v);

    cout << ans << endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
