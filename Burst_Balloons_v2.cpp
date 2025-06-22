#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>

using namespace std;

int backtrack(int l,int r,vector<int>& s,int first,vector<vector<int>>& dp)
{
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    int ans = INT_MIN;
    for(int i=l;i<=r;i++)
    {
        if(first) {
            ans = max(
                ans,
                backtrack(l,i-1,s,0,dp)+backtrack(i+1,r,s,0,dp)+s[i]
            );
        }
        else {
            ans = max(
                ans,
                backtrack(l,i-1,s,0,dp)+backtrack(i+1,r,s,0,dp)+(s[l-1]*s[r+1])
            );
        }
    }
    return dp[l][r] = ans;
}

void solve(int cs)
{
    int n;
    cin >> n;
    vector<int> s;

    s.push_back(1);
    for(int i=0;i<n;i++) 
    {
        int x;cin >> x;s.push_back(x);
    }
    s.push_back(1);

    vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

    cout << backtrack(1,n,s,1,dp) << endl;
}

void io()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    // io();

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
