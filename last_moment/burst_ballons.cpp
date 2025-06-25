#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

int n,dp[111][111];

int ballon(int l,int r,int f,vector<int> &s)
{
    if(l>r) return 0;
    
    int &val = dp[l][r];
    if(val!=-1) return val;

    val = INT_MIN;
    for(int i=l;i<=r;i++)
    {
        if(f==1)
        {
            val = max(val, ballon(l,i-1,0,s)+ballon(i+1,r,0,s)+s[i]);
        }
        else
        {
            val = max(val, ballon(l,i-1,0,s)+ballon(i+1,r,0,s)+(s[l-1]*s[r+1]));
        }
    }

    return val;
}

void solve(int cs)
{
    cin >> n;
    vector<int> s={1};
    for(int i=0;i<n;i++)
    {
        int x;cin >>x;
        s.push_back(x);
    }
    s.push_back(1);

    memset(dp,-1,sizeof(dp));

    int ans = ballon(1,n,1,s);
    cout << ans << "\n";
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
    
    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
