#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> let = {"","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
int n;
string num;
vector<string> ans;

void dfs(int cur,string s)
{
    if(cur==n)
    {
        ans.push_back(s);
        return;
    }
    string tem = let[num[cur]-'1'];
    // cout << tem << endl;
    for(char c:tem)
        dfs(cur+1,s+c);
}
void solve(int cs)
{
    cin >> num;
    n = num.size();
    dfs(0,"");

    for(string s:ans) cout << s << ' ';
    cout << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
