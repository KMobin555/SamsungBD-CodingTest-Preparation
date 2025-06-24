#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> s,tem;
int n,ans;

int dfs(int i,int j,int canbomb,vector<vector<int>> s)
{
    if(i<0 || j>=5 || j<0) return 0;
    if(s[i][j]==2) return 0;


    int cnt = (s[i][j]==1);

    if(canbomb)
    {
        tem = s;

        for(int p=max(0,i-5);p<i;p++)
        {
            for(int q=0;q<5;q++)
            {
                if(tem[p][q]==2) tem[p][q] = 0;
            }
        }

        int op1 = 0,op2 = 0,op3=0;
        op1 = dfs(i-1,j+1,0,tem);
        op2 = dfs(i-1,j,0,tem);
        op3 = dfs(i-1,j-1,0,tem);

        int case1 = max({op1,op2,op3})+cnt;

        op1 = 0,op2 = 0,op3=0;
        op1 = dfs(i-1,j+1,1,s);
        op2 = dfs(i-1,j,1,s);
        op3 = dfs(i-1,j-1,1,s);

        int case2 = max({op1,op2,op3})+cnt;

        return max(case1,case2);
    }
    else
    {
        int op1 = 0,op2 = 0,op3=0;
        op1 = dfs(i-1,j+1,0,s);
        op2 = dfs(i-1,j,0,s);
        op3 = dfs(i-1,j-1,0,s);

        int case1 = max({op1,op2,op3})+cnt;
        return case1;
    }
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
    ans = dfs(n,2,1,s);

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
