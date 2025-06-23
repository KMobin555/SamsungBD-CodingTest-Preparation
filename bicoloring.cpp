/*
UVA problem
*/

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<int> adj[200];

bool bicolorable(int u,int col[])
{
    bool flag = true;
    for(int v:adj[u])
    {
        if(col[v]==-1)
        {
            col[v] = 1-col[u];
            flag&=bicolorable(v,col);
        }
        else if(col[v]==col[u]) return false;
    }
    return flag;
}

void solve(int cs)
{
    while(cin >> n && n!=0)
    {
        for(int i=0;i<200;i++) adj[i].clear();
        int m;cin >> m;
        while(m--)
        {
            int x,y;cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int col[200];
        for(int i=0;i<200;i++) col[i] = -1;
        col[0] = 0;
        if(!bicolorable(0,col)) cout << "NOT ";
        cout << "BICOLORABLE." << endl;
    }
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
