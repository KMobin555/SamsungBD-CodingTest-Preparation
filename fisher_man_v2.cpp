#include<iostream>
#include<cstdio>

using namespace std;
#define sz 50
int ans,n;
int gate[sz],man[sz];
int arr[sz],perm[sz],check[sz];

void back(int arr[],int idx)
{
    int cur = perm[idx];
    int pos = gate[cur];
    int num = man[cur];
    int i=0;
    while(num>0 && i<n)
    {
        // cout << i << endl;
        if(i==0 && arr[pos]==0)
        {
            arr[pos] = 1;
            num--;
        }
        else
        {
            int left = pos-i;
            int right = pos+i;

            if(left>=1 && right<=n && arr[left]==0 && arr[right]==0 && num==1)
            {
                int tem_arr[sz] = {};
                for(int i=1;i<=n;i++) tem_arr[i] = arr[i];

                num--;
                tem_arr[left] = abs(pos-left)+1;
                back(tem_arr,idx+1);
                arr[right] = abs(pos-right)+1;
                back(arr,idx+1);
            }

            if(left>=1 && arr[left]==0 && num>0)
            {
                arr[left] = abs(pos-left)+1;
                num--;
            }
            if(right<=n && arr[right]==0 && num>0)
            {
                arr[right] = abs(pos-right)+1;
                // cout << "dd"<< endl;
                num--;
            }
        }
        i++;
    }
    if(idx>=3)
    {
        int sum=0;
        for(int i=1;i<=n;i++) sum+=arr[i];
        // cout << sum << endl;
        ans=min(ans,sum);
    }
    else back(arr,idx+1);
}

void all_pos(int idx)
{
    if(idx>3)
    {
        for(int i=1;i<=n;i++) arr[i] = 0;
        back(arr,1);
        return;
    }

    for(int i=1;i<=3;i++)
    {
        if(!check[i])
        {
            check[i] = 1;
            perm[idx] = i;
            all_pos(idx+1);
            check[i] = 0;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    // cout << n << endl;
    for(int i=1;i<=3;i++) cin >> gate[i];
    for(int i=1;i<=3;i++) cin >> man[i];

    // cout << "gg " << gate[0] << endl;
    
    ans = 9999;
    all_pos(1);

    cout << ans << endl;
    for(int i=0;i<sz;i++)
    {
        gate[i] = man[i] = arr[i] = perm[i] = check[i] = 0;
    }
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
