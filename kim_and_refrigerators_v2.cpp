#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;
#define point pair<int,int>
int ans,n;
point src,des;
vector<point> s(22);
bool vis[22];
int dp[1<<12][22];

int cost(int i,int j)
{   
    point a = s[i], b = s[j];
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int back(int mask,int src)
{
    if(mask == ((1<<n)-1))
    {
        return cost(src,n+1);
    }  
    int &tem = dp[mask][src];
    if(tem!=-1) return tem;

    tem = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        if(mask & (1<<(i-1))) continue;

        tem = min(tem, back(mask|(1<<(i-1)),i)+cost(src,i));
    }
    return tem;
}

void solve(int cs)
{
    cin >> n;
    cin >> s[0].first >> s[0].second >> s[n+1].first >> s[n+1].second;
    for(int i=1;i<=n;i++) 
    {
        cin >> s[i].first >> s[i].second;
    }
    // for(int i=0;i<n;i++) cout << s[i].second << ' ';cout << endl;
    // return;
    memset(dp,-1,sizeof(dp));
    ans = 999999;
    vector<int> v;
    ans = back(0,0);

    cout << "# " << cs << " ";
    cout << ans << endl;

    s.clear();
}

void io()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{

    // io();
    
    int t = 10, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
