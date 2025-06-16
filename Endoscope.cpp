#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int g[55][55];
bool vis[55][55];
int n,m,l;

bool up(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    int p = g[x][y];
    if(p==1 || p==2 || p==4 || p==7) return true;
    return false;
}

bool down(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    int p = g[x][y];
    if(p==1 || p==2 || p==5 || p==6) return true;
    return false;
}

bool right(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    int p = g[x][y];
    if(p==1 || p==3 || p==4 || p==5) return true;
    return false;
}

bool left(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    int p = g[x][y];
    if(p==1 || p==3 || p==6 || p==7) return true;
    return false;
}


void solve(int cs)
{
    int x,y;
    cin >> n >> m >> x >> y >> l;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> g[i][j];
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    memset(vis,false,sizeof(vis));

    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},1});
    vis[x][y] = true;
    int ans = 0;

    while(!q.empty())
    {
        x = q.front().first.first;
        y = q.front().first.second;
        int cur_l = q.front().second;
        q.pop();


        if(cur_l>l) continue;
        ans++;
        // cout << x << ' ' << y << " val "<< g[x][y] << " level-> " << cur_l << endl;

        if(up(x,y) && down(x-1,y) && !vis[x-1][y])
        {
            // cout << x << ' ' << y << " to " << x-1 << ' ' << y << endl;
            vis[x-1][y] = true;
            q.push({{x-1,y},cur_l+1});
        }

        if(down(x,y) && up(x+1,y) && !vis[x+1][y])
        {
            // cout << x << ' ' << y << " to " << x+1 << ' ' << y << endl;
            vis[x+1][y] = true;
            q.push({{x+1,y},cur_l+1});
        }
        
        if(right(x,y) && left(x,y+1) && !vis[x][y+1])
        {
            // cout << x << ' ' << y << " to " << x << ' ' << y+1 << endl;
            vis[x][y+1] = true;
            q.push({{x,y+1},cur_l+1});
        }

        if(left(x,y) && right(x,y-1) && !vis[x][y-1])
        {
            // cout << x << ' ' << y << " to " << x << ' ' << y-1 << endl;
            vis[x][y-1] = true;
            q.push({{x,y-1},cur_l+1});
        }


        // g[x][y] = 0;
    }

    cout << ans << endl;
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
