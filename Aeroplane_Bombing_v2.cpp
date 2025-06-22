#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;


int back(int i,int j,bool doBomb, vector<vector<int>> s,int row_cnt)
{
    if(i<0 || j<0 || j>=5) return 0;

    if(s[i][j]==2)
    {
        if(row_cnt>5 && doBomb) return 0;
        else if(!doBomb) doBomb = true;
    }

    int val = 0;
    for(int p=-1;p<=1;p++)
    {
        if(doBomb)
        {
            val=max(val,back(i-1,j+p,true,s,row_cnt+1));
        }
        else
        {
            val = max(val,back(i-1,j+p,false,s,1));
            val = max(val,back(i-1,j+p,true,s,row_cnt+1));
        }
    }

    return (s[i][j]==1)?1+val:val;
}

void solve(int cs)
{
    int n;
    cin >> n;
    
    vector<vector<int>> s(n+1,vector<int>(5,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++) cin >> s[i][j];
    }
    
    int ans = back(n,2,false,s,0);

    cout << "#" << cs << " ";
    cout << ans << "\n";
}

void io()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
int main()
{
    // io();

    int t = 1, cs = 1;
    cin >> t;
    while(t--) solve(cs++);

    return 0;
}
