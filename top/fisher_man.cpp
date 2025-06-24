#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

const int sz = 111;
int check[sz],perm[sz],gate[sz],num[sz],arr[sz]; 
int n,ans;

void distribute(int arr[],int ind)
{
    int cur = perm[ind];
    int pos = gate[cur];
    int cnt = num[cur],i=0;
    while(cnt>0 && i<n)
    {
        int left = pos-i;
        int right = pos+i;

        if(left>0 && right<=n && arr[left]==0 && arr[right]==0 && cnt==1)
        {
            int tem[sz] = {};
            for(int i=1;i<=n;i++) tem[i] = arr[i];

            cnt--;

            tem[left] = abs(left-pos)+1;
            distribute(tem, ind+1);

            arr[right] = abs(right-pos)+1;
            distribute(arr, ind+1);
        }
        if(left>0 && cnt>0 && arr[left]==0)
        {
            arr[left] = abs(pos-left)+1;
            cnt--;
        }
        if(right<=n && cnt>0 && arr[right]==0)
        {
            arr[right] = abs(pos-right)+1;
            cnt--;
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
        distribute(arr, ind+1);
    }
}

void all_possible(int ind)
{
    if(ind>3)
    {
        // for(int i=1;i<=3;i++) cout << perm[i] << ' ';cout << endl;
        for(int i=1;i<=n;i++) arr[i] = 0;
        distribute(arr, 1);
    }

    for(int i=1;i<=3;i++)
    {
        if(!check[i])
        {
            check[i] = 1;
            perm[ind] = i;
            all_possible(ind+1);
            check[i] = 0;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    for(int i=1;i<=3;i++) cin >> gate[i];
    for(int i=1;i<=3;i++) cin >> num[i];

    ans = INT_MAX;
    all_possible(1);

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

    io();
    
    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
