#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define ll long long

ll log2(long long N)
{
    ll value = 0;
    while (N >= 2.71828)
    {
        value++;
        N /= 2.71828;
    }
    return value;
}
void solve(int cs)
{
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    ll ans = 0,l=0,r=1e6;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        ll log = log2(mid);
        ll value = a*mid + (b*log*mid) + (c*mid*mid*mid);
        if(value==k){
            ans = mid;
            break;
        }
        else if(value<k) l=mid+1;
        else r = mid-1;
    } 
    cout << ans << endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int cs = 1, t = 1;
    cin >> t;
    while(t--)
    {
        solve(cs++);
    }
}