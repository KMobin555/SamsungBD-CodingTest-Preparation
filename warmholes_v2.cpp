#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<climits>

using namespace std;

#define point pair<int,int>
#define pqitem pair<int,point>
int n;

void solve(int cs)
{
    cin >> n;
    point st,dis;
    cin >> st.first >> st.second >> dis.first >> dis.second;

    map<point,vector<pair<point,int>>> graph;
    vector<point> s;
    s.push_back(st);
    s.push_back(dis);

    for(int i=0;i<n;i++)
    {
        point a,b;
        int c;
        cin >> a.first >> a.second >> b.first >> b.second >> c;

        s.push_back(a);
        s.push_back(b);

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    int points_size = s.size();
    for(int i=0;i<points_size;i++)
    {
        for(int j=i+1;j<points_size;j++)
        {
            point a = s[i], b = s[j];
            int c = abs(a.first-b.first)+abs(a.second-b.second);
            // cout << c << endl;
            
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
    }

    // for(auto [a,b]:graph) cout << a.first << ' ' << a.second << endl;

    priority_queue<pqitem, vector<pqitem>, greater<pqitem>> pq;
    map<point,int> dist;
    set<point> vis;

    for(auto &p:s) dist[p] = INT_MAX;
    pq.push({0,st});
    dist[st] = 0;

    while(!pq.empty())
    {
        auto [_,u] = pq.top();pq.pop();
        // cout << _ << endl;
        if(vis.count(u)) continue;
        vis.insert(u);

        for(auto &[v,cost]:graph[u])
        {
            if(dist[v]>dist[u]+cost)
            {
                dist[v] = dist[u]+cost;
                pq.push({dist[v],v});
            }
        }
    }

    cout << dist[dis] << "\n";
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
