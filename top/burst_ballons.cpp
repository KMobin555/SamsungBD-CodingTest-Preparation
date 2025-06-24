#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n;

int back(int l,int r,vector<int> &s, int is_first)
{
    if(l>r) return 0;

    int val = 0;
    for(int i=l;i<=r;i++)
    {
        if(is_first)
        {
            val = max(val, back(l,i-1,s,0)+back(i+1,r,s,0)+s[i]);
        }
        else
        {
            val = max(val, back(l,i-1,s,0)+back(i+1,r,s,0)+(s[l-1]*s[r+1]));
        }
    }
    return val;
}
void solve(int cs)
{
    cin >> n;
    vector<int> s;
    s.push_back(1);
    for(int i=0;i<n;i++) 
    {
        int x;cin >> x;
        s.push_back(x);
    }
    s.push_back(1);

    int ans = back(1,n,s,1);

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
