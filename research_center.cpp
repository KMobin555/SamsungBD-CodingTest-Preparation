/*
A research team wants to establish a research center in a region where rare elements have been found. The goal is to build the center such that it is as close as possible to all the rare-element locations to minimize overall research costs.

    The region is represented as a square matrix (size ≤ 20).

    Each cell in the matrix can be:

        1: Road (the research center can only be built on roads)

        0: No road

    The locations of rare elements (up to 5) are given as coordinates within the matrix.

    All rare-element locations are connected by roads.

    The task is to find a location on the road where the maximum distance from that location to any rare-element location is minimized.

In other words, you want to find a road cell that minimizes the longest shortest path to any rare-element location.

*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
#include<queue>

using namespace std;

int vis[20][20],s[20][20];
int n,m;
int loc[6][2];
int X[4] = {1,-1,0,0}, Y[4] = {0,0,1,-1};

bool valid(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<n);
}

void traverse(int x,int y,int val)
{
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(vis[loc[i][0]][loc[i][1]] > 0) cnt++;
    }
    if(cnt>=m) return;

    if(s[x][y]==3) return;

    for(int i=0;i<4;i++)
    {
        int newx = x+X[i], newy = y+Y[i];
        if(!valid(newx,newy)) continue;
        if(s[newx][newy]==0) continue;
        if(vis[newx][newy]>0) continue;

        vis[newx][newy] = val+1;
        traverse(newx,newy,val+1);
    }
}

void traverse2(int x,int y,int val)
{
    memset(vis,0,sizeof(vis));
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},1});
    vis[x][y] = val;

    while(!q.empty())
    {
        x = q.front().first.first;
        y = q.front().first.second;
        val = q.front().second;
        q.pop();

        vis[x][y] = val;

        for(int i=0;i<4;i++)
        {
            int newx = x+X[i], newy = y+Y[i];
            if(!valid(newx,newy)) continue;
            if(s[newx][newy]==0) continue;
            if(vis[newx][newy]>0) continue;

            q.push({{newx,newy},val+1});
        }
    }
}

void solve(int cs)
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> loc[i][0] >> loc[i][1];
        loc[i][0]--;
        loc[i][1]--;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> s[i][j];
    }

    for(int i=0;i<m;i++)
    {
        s[loc[i][0]][loc[i][1]] = 3;
    }

    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]!=1) continue;
            int tem = 0;

            traverse2(i,j,1);

            // cout << i << ' ' << j << endl;
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<n;j++) cout << vis[i][j] << ' ';
            //     cout << endl;
            // }

            for(int k=0;k<m;k++)
            {
                if(tem < vis[loc[k][0]][loc[k][1]]) 
                    tem = vis[loc[k][0]][loc[k][1]];
            }

            if(ans > tem)
                ans = tem;
        }   
    }

    
    cout << ans-1 << "\n";
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
