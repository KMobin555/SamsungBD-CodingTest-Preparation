#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>

using namespace std;

int dp[20][20];

int dfs(int i,int j,int c,vector<int> s)
{
    if(i>j) return 0;
    int ans = INT_MIN;

    if(~dp[i][j]) return dp[i][j];

    for(int p=i;p<=j;p++)
    {
        if(c==1)
        {
            ans = max(ans, dfs(i,p-1,1,s)+dfs(p+1,j,1,s)+(s[i-1]*s[j+1]));
        }
        else
        {
            ans = max(ans, dfs(i,p-1,1,s)+dfs(p+1,j,1,s)+s[p]);
        }
    }

    return dp[i][j] = ans;
}

void solve(int cs)
{
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    s.insert(s.begin(),1);
    s.push_back(1);

    memset(dp,-1,sizeof(dp));

    int ans = dfs(1,n,0,s);

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

    while(t--) 
        solve(cs++);

    return 0;
}
