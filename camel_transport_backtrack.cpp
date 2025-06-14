#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

bool left_vis[200],right_vis[200];
int n, ans = INT_MAX;

void back(int do_left,int cost,vector<int> s)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(right_vis[i]) cnt++;
    }

    if(cnt==n)
    {
        ans=min(ans,cost);
    }

    if(do_left)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(left_vis[i] && left_vis[j])
                {
                    left_vis[i] = false;
                    left_vis[j] = false;
                    right_vis[i] = true;
                    right_vis[j] = true;
                    back(0,cost+max(s[i],s[j]),s);
                    left_vis[i] = true;
                    left_vis[j] = true;
                    right_vis[i] = false;
                    right_vis[j] = false;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(right_vis[i])
            {
                right_vis[i] = false;
                left_vis[i] = true;
                back(1,cost+s[i],s);
                right_vis[i] = true;
                left_vis[i] = false;
            }
        }
    }
}


void solve(int cs)
{
    cin >> n;
    vector<int> s(n);
    for(int &x:s) cin >> x;
    sort(s.begin(),s.end());

    memset(left_vis,true,sizeof(left_vis));
    memset(right_vis,false,sizeof(right_vis));

    ans=INT_MAX;
    back(1,0,s);

    cout << ans << "\n";
    
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
