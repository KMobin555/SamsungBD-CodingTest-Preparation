#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
int k;
string s;

int get_sum(string s)
{
    int sum = 0;
    for(char c:s) sum = sum*10+(c-'0');
    return sum;
}

void solve(int cs)
{
    cin >> k;
    cin >> s;

    stack<char> stk;
    int ans[20] = {0};
    int n = s.size();
    string tem = "";
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') stk.push('(');
        else if(s[i]==')') stk.pop();
        else 
        {
            while(s[i]!='(' && s[i]!=')' && i<n)
            {
                tem+=s[i];
                i++;
            }
            // cout << stk.size() << endl;
            ans[stk.size()-1] += get_sum(tem);
            // cout << tem << endl;
            tem = "";
            i--;
        }
    }
    cout << ans[k] << endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1, cs = 1;
    // cin >> t;
    while(t--) solve(cs++);

    return 0;
}
