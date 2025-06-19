#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,k,ans;

void flip(int col, vector<vector<int>> &s)
{
    for(int i=0;i<n;i++) 
        s[i][col] = !s[i][col];
}

void check(int col,int k, vector<vector<int>> s)
{
    if(k==0)
    {
        int cnt2=0;
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<m;j++) 
                if(s[i][j]==1) cnt++;
            if(cnt==m) cnt2++;
        }
        ans=max(ans,cnt2);
        return;
    }

    if(col>=m) return;

    check(col+1,k,s);

    vector<vector<int>> cpy=s;
    for(int i=1;i<=k;i++)
    {
        flip(col,cpy);
        check(col+1,k-i,cpy);
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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
