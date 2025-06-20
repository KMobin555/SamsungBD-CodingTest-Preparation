#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int n, ans;
vector<vector<int>> final_vec;
vector<int> X = {0,0,1,-1}, Y = {1, -1, 0, 0};

bool valid(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<n);
}

void dfs(int x,int y,int cnt,vector<vector<int>> s)
{
    if(x==n-1 && y==n-1)
    {
        s[x][y] = 3;
        if(cnt>ans)
        {
            ans = cnt;
            final_vec = s;
        }
    }

    for(int i=0;i<4;i++)
    {
        int new_x = x+X[i], new_y = y+Y[i];
        if(!valid(new_x,new_y)) continue;

        if(s[new_x][new_y] == 1) continue;
        if(s[new_x][new_y] == 3) continue;


        if(s[new_x][new_y] == 0) 
        {
            s[x][y] = 3;
            dfs(new_x,new_y,cnt,s);
        }
        if(s[new_x][new_y] == 2) 
        {
            s[x][y] = 3;
            dfs(new_x,new_y,cnt+1,s);
        }
    }

}

void solve(int cs)
{
    cin >> n;
    vector<vector<int>> s(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> s[i][j];     
    }
    ans = 0;
    dfs(0,0,0,s);

    cout << "Case #" << cs << "\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << final_vec[i][j] << ' ';
        }
        cout << "\n";
    }
    cout << ans << "\n\n";
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
