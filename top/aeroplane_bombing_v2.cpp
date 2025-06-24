#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> s,tem;
int n,ans;

int dfs(int i,int j,int canBomb,int cur)
{
    if(i<0 || j>=5 || j<0) return 0;
    
    if(s[i][j]==2)
    {
        if(canBomb && cur>5) return 0;
        else if(!canBomb) canBomb = 1;
    }

    int val = 0;
    for(int p=-1;p<=1;p++)
    {
        if(canBomb)
        {
            val = max(val,dfs(i-1,j+p,1,cur+1));
        }
        else
        {
            val = max(val,dfs(i-1,j+p,1,cur+1));
            val = max(val,dfs(i-1,j+p,0,1));
        }
    }
    return val+(s[i][j]==1);
}

void solve(int cs)
{
    cin >> n;
    s.clear();
    s.resize(n+1,vector<int>(5,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++) cin >> s[i][j];
    }

    ans = 0;
    ans = dfs(n,2,0,0);

    cout << "#" << cs << " ";
    cout << ans << endl;
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

    // io();
    
    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
