#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[4040][1010][5];
const int inf = 2e9;

int energy(int h,int d,int k,int cost[],int time[])
{
    if(h<=0) return inf;
    if(d==0) return 0;
    if(k<0) return inf;
    if(dp[h][d][k]!=-1) return dp[h][d][k];
    return dp[h][d][k] = min(
        energy(h-cost[k],d-1,k,cost,time) + time[k],
        energy(h,d,k-1,cost,time)
    );
}

void solve(int cs)
{
    int h,d,cost[5],time[5];
    cin >> h >> d;
    for(int i=0;i<5;i++) cin >> cost[i];
    for(int i=0;i<5;i++) cin >> time[i];

    memset(dp,-1,sizeof(dp));
    int ans = energy(h,d,4,cost,time);

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

    io();
    
    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
