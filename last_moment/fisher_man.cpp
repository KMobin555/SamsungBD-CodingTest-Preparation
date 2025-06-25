#include<iostream>
#include<cstdio>

using namespace std;

const int sz = 111;
int ans,n,gate[sz],man[sz],perm[sz],arr[sz],check[sz];

void distribute(int arr[],int ind)
{
    int cur = perm[ind];
    int pos = gate[cur], num = man[cur], i=0;

    while(num>0 && i<n)
    {
        int left = pos-i;
        int right = pos+i;

        if(left>0 && right<=n && arr[left]==0 && arr[right]==0 && num==1)
        {
            int tem[sz] = {};
            for(int i=1;i<=n;i++) tem[i] = arr[i];

            num--;

            tem[left] = abs(pos-left)+1;
            distribute(tem,ind+1);

            arr[right] = abs(pos-right)+1;
            distribute(arr,ind+1);
        }

        if(left>0 && arr[left]==0 && num>0)
        {
            arr[left] = abs(left-pos)+1;
            num--;
        }

        if(right<=n && arr[right]==0 && num>0)
        {
            arr[right] = abs(right-pos)+1;
            num--;
        }

        i++;
    }

    if(ind>=3)
    {
        int sum = 0;
        for(int i=1;i<=n;i++) sum+=arr[i];
        ans = min(ans,sum);
    }
    else
    {
        distribute(arr,ind+1);
    }
}

void all(int ind)
{
    if(ind>3)
    {
        for(int i=1;i<=n;i++) arr[i] = 0;
        distribute(arr,1);
    }

    for(int i=1;i<=3;i++)
    {
        if(!check[i])
        {
            check[i] = 1;
            perm[ind] = i;
            all(ind+1);
            check[i] = 0;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    for(int i=1;i<=3;i++) cin >> gate[i];
    for(int i=1;i<=3;i++) cin >> man[i];

    ans = 2e9;
    all(1);

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
