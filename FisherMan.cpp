#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


void solve(int cs)
{
    int a[3],b[3],n;
    cin >> n;
    for(int i=0;i<3;i++) cin >> a[i];
    for(int i=0;i<3;i++) cin >> b[i];

    int ans = n*4;

    for(int i=1;i<=n-(b[0]+b[1]+b[2])+1;i++)
    {
        for(int j=i+b[0];j<=n-(b[1]+b[2])+1;j++)
        {
            for(int k=j+b[1];k<=n-b[2]+1;k++)
            {

                int sum = 0;

                for(int p=i;p<i+b[0];p++) sum+=abs(p-a[0])+1;

                for(int p=j;p<j+b[1];p++) sum+=abs(p-a[1])+1;

                for(int p=k;p<k+b[2];p++) sum+=abs(p-a[2])+1;


                ans = min(ans,sum);
            }
        }
    }

    cout << ans << "\n";
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
