#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


void solve(int cs)
{
    int n,k;
    cin >> n >> k;
    int s[n];
    for(int i=0;i<n;i++) cin >> s[i];

    sort(s,s+n,greater<>());
    int ans = 0,d=n-1;
    while(k--)
    {
        for(int i=0;i<n;i++)
        {
            ans+=s[d];
            s[i]-=s[d];
        }
        d--;
    }
    cout << ans << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
