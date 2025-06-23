#include<iostream>
#include<cstdio>

using namespace std;

int n,m;
char s[111][111];
int X[8] = {0,0,1,-1,1,-1,1,-1};
int Y[8] = {1,-1,0,0,1,1,-1,-1};

void dfs(int i,int j)
{
    s[i][j] = '*';
    for(int k=0;k<8;k++)
    {
        int x = i+X[k], y = j+Y[k];
        if(x>=0 && x<n && y>=0 && y<m && s[x][y]=='@')
            dfs(x,y);
    }
}

void print_graph()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int cs)
{
    while(cin >> n >> m && n!=0 && m!=0)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) cin >> s[i][j];

        // print_graph();

        int ans = 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='@')
                {
                    ans++;
                    dfs(i,j);
                }
            }

        cout << ans << endl;
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
