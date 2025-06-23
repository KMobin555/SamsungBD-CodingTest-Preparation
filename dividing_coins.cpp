#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,s[110];
int dp[110][110*501];

int back(int ind,int diff)
{
    if(ind==n) return diff;

    int &cur = dp[ind][diff];

    if(cur!=-1) return cur;

    cur = min(back(ind+1,diff+s[ind]),back(ind+1,abs(diff-s[ind])));
    return cur;
}

void solve(int cs)
{
    cin >> n;
    int total = 0;
    for(int i=0;i<n;i++) cin >> s[i],total+=s[i];

    memset(dp,-1,sizeof(dp));
    int ans = back(0,0);

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
