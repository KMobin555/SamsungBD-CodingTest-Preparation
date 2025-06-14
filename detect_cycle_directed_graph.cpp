#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> adj[100],ans;
int n,m,max_sum;
bool vis[100];

int node_sum(vector<int> s)
{
    int sum=0;
    for(int x:s) sum+=x;
    return sum;
}

void dfs(int u,vector<int> s)
{
    vis[u] = true;
    s.push_back(u);

    for(int v:adj[u])
    {
        if(!vis[v]) dfs(v,s);
        else{
            if(s[0]!=v) continue;
            if(node_sum(s)<max_sum)
            {
                max_sum = node_sum(s);
                ans=s;
            }
        }
    }

    vis[u] = false;
    s.pop_back();
}

void solve(int cs)
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
    }
    

    max_sum = (n*(n+1))/2 + 100;
    
    for(int i=1;i<=n;i++)
    {
        vector<int> s;
        memset(vis,false,sizeof(vis));
        dfs(i,s);
    }

    sort(ans.begin(),ans.end());
    for(int x:ans) cout << x << ' ';
    cout << endl;

    for(int i=0;i<100;i++) adj[i].clear();
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
