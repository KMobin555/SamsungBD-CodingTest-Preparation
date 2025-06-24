#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

int dp[4040][1010][5];
const int inf = 2e9;

int back(int h,int d,int cost[],int time[],int k)
{
    if(h<=0) return inf;
    if(d==0) return 0;
    if(k<0) return inf;
    if(dp[h][d][k]!=-1) return dp[h][d][k];
    return dp[h][d][k] = min(
        back(h-cost[k],d-1,cost,time,k)+time[k],
        back(h,d,cost,time,k-1)
    );
}

void solve(int cs)
{
    int h,d;
    int cost[5],time[5];

    cin >> h >> d;
    for(int i=0;i<5;i++) cin >> cost[i];
    for(int i=0;i<5;i++) cin >> time[i];

    memset(dp,-1,sizeof(dp));

    int ans = back(h,d,cost,time,4);

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
