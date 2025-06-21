
/*
You are given an array of integers which represents positions available and an integer c(cows).
Now you have to choose c positions such that minimum difference between cows is maximized.
For example,
1 3 5 8 10
c=3

Output: 4
1 5 10
*/

#include<iostream>
#include<cstdio>

using namespace std;

int s[2000],n,c;

bool is_possible(int x)
{
    int last = 0, cnt = 1;
    for(int i=1;i<n;i++)
    {
        if((s[i]-s[last])>=x)
        {
            last = i;
            cnt++;
            if(cnt==c) return true;
        }
    }

    return false;
}

void solve(int cs)
{
    cin >> n >> c;
    for(int i=0;i<n;i++) cin >> s[i];

    int l = 0, r = s[n-1]-s[0] + 1;

    while(l<r)
    {
        int mid = (l+r+1)/2;

        if(is_possible(mid))
        {
            l=mid;
        }
        else r = mid-1;
    }

    cout << l << "\n";
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
