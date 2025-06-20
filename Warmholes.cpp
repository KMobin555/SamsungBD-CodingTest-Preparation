#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

struct hole
{
    int si,sj,di,dj,c;
};

vector<hole> s(100);
int n,si,sj,di,dj,ans;
bool vis[100];

void back(vector<int> &v)
{
    int sum = 0,li=si,lj=sj;
    for(int x:v)
    {
        sum+=abs(s[x].si-li)+abs(s[x].sj-lj);
        sum+=s[x].c;

        li = s[x].di;
        lj = s[x].dj;
    }
    sum+=abs(li-di)+abs(lj-dj);
    ans = min(ans,sum);


    sum = 0,li=si,lj=sj;
    for(int x:v)
    {
        sum+=abs(s[x].di-li)+abs(s[x].dj-lj);
        sum+=s[x].c;

        li = s[x].si;
        lj = s[x].sj;
    }
    sum+=abs(li-di)+abs(lj-dj);
    ans = min(ans,sum);


    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            v.push_back(i);
            back(v);
            v.pop_back();
            vis[i] = false;
        }
    }
}

void solve(int cs)
{
    cin >> n;
    cin >> si >> sj >> di >> dj;
    for(int i=0;i<n;i++)
    {
        cin >> s[i].si >> s[i].sj >> s[i].di >> s[i].dj >> s[i].c;
    }

    vector<int> v;
    ans = INT_MAX;
    memset(vis,false,sizeof(vis));
    back(v);

    cout << ans << endl;
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
