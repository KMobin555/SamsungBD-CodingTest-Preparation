#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


void solve(int cs)
{
    int n;
    cin >> n;
    vector<int> s(n);
    for(int &x:s) cin >> x;
    sort(s.begin(),s.end());

    int ans = 0;
    while(n>3)
    {
        int case1 = s[n-1]+s[0]+s[n-2]+s[0];
        int case2 = s[1]+s[0]+s[n-1]+s[1];
        ans+=min(case1,case2);
        n-=2;
    }
    if(n==3) ans+=s[0]+s[1]+s[2];
    else if(n==2) ans+=s[1];
    else ans+=s[0];

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
