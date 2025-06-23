#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> final_ans, temp_path, adj[55];
int n, m, ans;
int vis[55], par[55];

void dfs(int u) {
    vis[u] = 1; 
    for (int v : adj[u]) {
        if (vis[v] == 1) { 
            temp_path.clear();
            int cur,sum = v;
            temp_path.push_back(v);
            for (cur = u; cur != v && cur != 0; cur = par[cur]) {
                sum += cur;
                temp_path.push_back(cur);
            }

            if (sum < ans) {
                ans = sum;
                final_ans = temp_path;
            }
        }
        else {
            par[v] = u;
            dfs(v);
        }
    }
    vis[u] = 2;
}

void solve(int cs) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    ans = 2e9;
    memset(par, 0, sizeof(par));
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++) {
        if(vis[i]!=2) dfs(i);
    }


    sort(final_ans.begin(), final_ans.end());
    for (int x : final_ans) cout << x << ' ';
    cout << endl;
}

void io() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

int main() {
    // io();
    int t = 1, cs = 1;
    // cin >> t;
    while (t--) solve(cs++);
    return 0;
}
