/*

problem link : 

https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/aeroplane-bombing

*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


int check(int cur,int ind,int canBomb,vector<vector<int>> g)
{
    if(cur<0 || ind<0 || ind>4 || g[cur][ind]==2) return 0;
    int case1 = 0, case2 = 0, cnt = 0;
    if(g[cur][ind]) cnt++;
    if(canBomb)
    {   
        vector<vector<int>> cpy=g;
        for(int i=max(0,cur-5);i<cur;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(g[i][j]==2) g[i][j] = 0;
            }
        }

        int op1=0,op2=0,op3=0;

        op1 = check(cur-1,ind-1,0,g);
        op2 = check(cur-1,ind,0,g);
        op3 = check(cur-1,ind+1,0,g);
        
        case1 = max({op1,op2,op3})+cnt;

        op1=0,op2=0,op3=0;

        op1 = check(cur-1,ind-1,1,cpy);
        op2 = check(cur-1,ind,1,cpy);
        op3 = check(cur-1,ind+1,1,cpy);

        int tem = max({op1,op2,op3})+cnt;
        case1 = max(case1,tem);
    }
    else
    {
        int op1=0,op2=0,op3=0;

        op1 = check(cur-1,ind-1,0,g);
        op2 = check(cur-1,ind,0,g);
        op3 = check(cur-1,ind+1,0,g);

        case2 = max({op1,op2,op3})+cnt;
    }
    return max(case1,case2);
}

void solve(int cs)
{
    int n;
    cin >> n;
    vector<vector<int>> g(n+1,vector<int>(5,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++) cin >> g[i][j];
    }
    for(int i=0;i<5;i++) g[n][i] = 0;

    int ans = check(n,2,1,g);

    cout << "#" << cs << " " << ans << "\n";
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