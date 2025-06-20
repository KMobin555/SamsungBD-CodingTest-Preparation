/*
Problem Description:

There is an island surrounded by oil mines. You are given:

    n companies

    m oil mines, each with a certain value

Your task is to distribute the oil mines among the n companies in a fair manner. The fairness is defined as follows:

    Each company must receive a contiguous segment of oil mines (i.e., if a company receives oil mines 2, 3, and 4, it cannot also receive oil mine 6 unless it also receives 5).

    No two companies can have interleaved or non-contiguous oil mines.

    After distributing all the oil mines, compute the difference between the maximum and minimum total value of oil mines assigned to any company.

    The goal is to make this difference as small as possible; that is, find the minimum possible difference between the company with the highest total value and the company with the lowest total value.

Input Format:

    The first line contains an integer T, the number of test cases.

    For each test case:

        The first line contains two integers n (number of companies) and m (number of oil mines).

        The next line contains m integers, representing the values of the oil mines.

Output Format:

    For each test case, output a single integer: the minimum possible difference between the maximum and minimum total value assigned to any company.

Example:

Input:

text
2
2 4
6 13 10 2
2 4
6 10 13 2

Output:

text
5
1

Explanation:

    In the first test case, the best way to split [6, 13, 10,o 2 contiguous groups is [6,and[10, (totals: 19 and 12, difference: 7), or [1] and [2] (totals: 6 and 25, difference: 19), etc. The minimum possible difference is 5.

    In the second test case, the best split is [1] and [2] (totals: 16 and 15, difference: 1).

Key Constraints:

    All oil mines must be assigned.

    Each company gets a contiguous block of oil mines.

    The objective is to minimize the difference between the company with the most and the company with the least total oil value.

give me the solution
give me the solution

*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>

using namespace std;
int c,n,s[100];
bool vis[100];
int ans;

void dfs(int cur,int sum,int com,int mn,int mx)
{
    if(vis[cur])
    {
        if(com==c)
        {
            int new_mn = min(mn,sum);
            int new_mx = max(mx,sum);
            ans = min(ans, new_mx-new_mn);
        }
        return;
    }

    vis[cur] = true;
    int nexcur = (cur+1)%n;

    dfs(nexcur,sum+s[cur],com,mn,mx);

    int new_mn = min(mn,sum);
    int new_mx = max(mx,sum);

    dfs(nexcur,s[cur],com+1,new_mn,new_mx);

    vis[cur] = false;
}

void solve(int cs)
{
    cin >> c >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    memset(vis,false,sizeof(vis));

    ans = INT_MAX;
    for(int i=0;i<n;i++)
        dfs(i,0,1,INT_MAX,INT_MIN);

    if(c>n) ans=-1;
    cout << ans << endl;
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
