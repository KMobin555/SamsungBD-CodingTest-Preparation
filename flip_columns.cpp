#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,k,ans;

void check(int col,int k, vector<vector<int>> s)
{
    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<m;j++) 
                if(s[i][j]==1) cnt++;
            if(cnt)
        }
    }
}

void solve(int cs)
{
    cin >> n >> m >> k;
    vector<vector<int>> s(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin >> s[i][j];
    } 
    ans = 0;
    check(0,k,s);

    cout << ans << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
