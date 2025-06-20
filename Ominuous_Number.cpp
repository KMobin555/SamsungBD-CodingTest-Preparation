#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


void solve(int cs)
{
    int a,b,k;
    cin >> a >> b >> k;
    int n;cin >> n;
    int ans=0,s[n];
    for(int i=0;i<n;i++) cin >> s[i];

    for(int p = a;p<=b;p++)
    {
        int cur = p;
        int dict[10] = {0};
        while(cur)
        {
            dict[cur%10]++;
            cur/=10;
        }

        int cnt = 0;
        for(int x:s) cnt+=dict[x];
        if(cnt<k) ans++;
    }
    cout << ans << "\n";
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
