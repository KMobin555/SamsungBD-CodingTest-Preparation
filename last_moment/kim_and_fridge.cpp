#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
using namespace std;

int ans,n,x[111],y[111];
bool vis[111];
int dp[1<<20][111];

int dist(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int short_path(int x,int mask)
{
    if(mask == ((1<<n)-1)) 
    {
        return dist(x,n+1);
    }

    int &val = dp[mask][x];

    if(val!=-1) return val;

    val = INT_MAX;

    for(int i=1;i<=n;i++)
    {
        if(mask & (1<<(i-1))) continue;

        val = min(val, short_path(i,mask|(1<<(i-1)))+dist(x,i));
    }

    return val;

}

void solve(int cs)
{
    cin >> n;
    cin >> x[0] >> y[0] >> x[n+1] >> y[n+1];
    for(int i=1;i<=n;i++) cin >> x[i] >> y[i],vis[i] = false;

    ans = INT_MAX;

    memset(dp,-1,sizeof(dp));

    ans = short_path(0,0);

    cout << "# " << cs << " ";
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
    
    int t = 10, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
