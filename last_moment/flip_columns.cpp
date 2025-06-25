#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;


void solve(int cs)
{
    int n,m,k;
    cin >> n >> m >> k;
    unordered_map<int,int> dist;

    for(int i=0;i<n;i++)
    {
        int zero = 0;
        int mask = 0;
        for(int j=0;j<m;j++)
        {
            int x;cin >> x;
            if(x==0) zero++;
            mask = (mask<<1) | x;
        }

        if(k>=zero && (k-zero)%2==0)
            dist[mask]++;
    }

    int ans = 0;
    for(auto [a,b]:dist) ans = max(ans,b);

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

    // io();
    
    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
