#include<iostream>
#include<cstdio>
#include<unordered_map>

using namespace std;


void solve(int cs)
{
    int n,m,k;
    cin >> n >> m >> k;
    unordered_map<string,int> dict;
    string tem = "";
    for(int i=0;i<n;i++)
    {
        int zeros = 0;
        tem = "";
        for(int j=0;j<m;j++)
        {
            int x;cin >> x;
            if(x==0) zeros++;
            tem+=(x+'0');
        }
        
        if(zeros<=k && (k-zeros)%2==0)
            dict[tem]++;
    }

    int ans = 0;
    for(auto [a,b]:dict) ans = max(ans,b);
    cout << ans << endl;
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
