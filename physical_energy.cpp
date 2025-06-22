#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>

using namespace std;

const int inf = 2e9;

int dp[4040][1010][5];
int back(int h,int d,int cost[],int time[],int n)
{
    if(h<0) return inf;
    if(d==0) return 0;
    if(n<0) return inf;

    if(dp[h][d][n]!=-1) return dp[h][d][n];

    // if(cost[cur-1]<=h) 
    // {
    //     int op1 = back(h-cost[cur-1],d-1,cost,time,cur)+time[cur-1];
    //     int op2 = back(h,d,cost,time,cur-1);
    //     return min(op1,op2);
    // }
    // else
    // {
    //     return back(h,d,cost,time,cur-1);
    // }
        
    // return min(back(h-cost[n],d-1,cost,time,n)+time[n], back(h,d,cost,time,n-1));

    return dp[h][d][n] = min(
        back(h-cost[n],d-1,cost,time,n) + time[n], 
        back(h,d,cost,time,n-1)
    );
}

void solve(int cs)
{
    int h,d;
    cin >> h >> d;
    // cout << h << d << endl;
    int cost[5],time[5];
    for(int i=0;i<5;i++) cin >> cost[i];
    for(int i=0;i<5;i++) cin >> time[i];

    memset(dp,-1,sizeof(dp));
    int ans = back(h,d,cost,time,4);
    cout << ans << endl;
}

void io()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{

    io();
    
    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
