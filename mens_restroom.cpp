#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


void solve(int cs)
{
    int n;
    cin >> n;
    vector<int> s(n,0);
    for(int i=0;i<n;i++)
    {
        int mx = 0, last_ind, cnt=0;
        for(int j=0;j<n;j++)
        {
            if(s[j]==0) cnt++;
            else cnt=0;
            
            if(cnt>=mx)
            {
                mx=cnt;
                last_ind = j;
            }
        }
        int st = last_ind - mx +1;
        int mid = (st+last_ind)/2;
        // cout << "lst indx " << last_ind << " mx len->" << mx << " st->" << st << endl;
        // cout << "mid " << mid << endl;
        s[mid] = 1;

        for(int p=0;p<n;p++) cout << (s[p]?"#":"_") << ' ';
        cout << endl;
    }    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
