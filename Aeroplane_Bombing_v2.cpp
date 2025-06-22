#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n,ans;
vector<vector<int>> s;

void back(int i,int j,int canBomb)
{
    if(canBomb)
    {

    }
    else
    {
        
    }
}

void solve(int cs)
{
    cin >> n;
    s.resize(n+1,vector<int>(5,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++) cin >> s[i][j];
    }
    
    ans = 99999999;

    back(n,2,1);

    cout << "#" << cs << " ";
    cout << ans << "\n";
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
