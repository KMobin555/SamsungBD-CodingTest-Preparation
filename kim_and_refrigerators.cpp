#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

int n,si,sj,di,dj,ans;
vector<pair<int,int>> s;
bool vis[20];

void all_pos(vector<int>& cur)
{
    if(cur.size()==n)
    {
        int x = si,y = sj, path=0;
        for(int i=0;i<n;i++)
        {
            path += abs(s[cur[i]].first-x) + abs(s[cur[i]].second-y);
            x = s[cur[i]].first;
            y = s[cur[i]].second;
        }
        path+=abs(di-x) + abs(dj-y);

        ans = min(ans,path);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            cur.push_back(i);
            all_pos(cur);
            cur.pop_back();
            vis[i] = false;
        }
    }
}

void solve(int cs)
{
    s.clear();
    memset(vis,false,sizeof(vis));

    cin >> n;
    cin >> si >> sj >> di >> dj;
    for(int i=0;i<n;i++)
    {
        int a,b;cin >> a >> b;
        s.push_back({a,b});
    }

    ans = INT_MAX;
    vector<int> v;
    all_pos(v);

    cout << "# " << cs << " " << ans << "\n";
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 10, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
