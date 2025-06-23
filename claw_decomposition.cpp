/*

https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2391

*/

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> adj[350];
int col[350];

bool bicol(int u,int col[])
{
    bool flag = true;
    for(int v:adj[u])
    {
        if(col[v]==-1)
        {
            col[v] = 1-col[u];
            flag &=bicol(v,col);
        }
        else if(col[u]==col[v]) return false;
    }

    return flag;
}

void solve(int cs)
{
    int t;
    while(cin>>t && t!=0)
    {
        for(int i=0;i<350;i++) adj[i].clear();
        int x,y;
        while(cin >> x >> y && (x!=0 && y!=0))
        {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=0;i<350;i++) col[i] = -1;
        bool ok = true;
        for(int i=1;i<=t;i++)
        {
            if(col[i]==-1)
            {
                col[i]=0;
                if(!bicol(i,col)) 
                {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok?"YES":"NO") << endl;
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
