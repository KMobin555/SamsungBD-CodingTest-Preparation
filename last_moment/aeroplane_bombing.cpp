#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

int n;
vector<vector<int>> s;

int plane(int i,int j,int canBomb,int cur_cnt)
{
    if(i<0 || j<0 || j>=5) return 0;

    if(s[i][j]==2)
    {
        if(canBomb && cur_cnt>5) return 0;
        else if(!canBomb) canBomb = 1;
    }

    int val = 0;

    for(int p=-1;p<=1;p++)
    {
        if(canBomb)
        {
            val = max(val, plane(i-1,j+p,1,cur_cnt+1));
        }
        else
        {
            val = max(val, plane(i-1,j+p,1,cur_cnt+1));
            val = max(val, plane(i-1,j+p,0,1));
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

    int ans = plane(n,2,0,0);

    cout << "#" << cs << " " << ans << "\n";
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
