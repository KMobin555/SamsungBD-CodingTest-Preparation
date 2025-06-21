/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful

2
6 10 40 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

6 0.774000  
3 0.700000
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

void dfs(int i,int n,int time,double prob,vector<pair<int,double>>s[],vector<double> &ans)
{
    if(time<=0)
    {
        // cout << i << " ans -> " << prob << endl;
        ans[i] += prob;
        return;
    }
    for(auto [a,b]:s[i])
    {
        // cout << a << ' ' << b << endl;
        if(b!=0.0)
        {
            prob*=b;
            // cout << "prob " << prob << endl;
            dfs(a,n,time-10,prob,s,ans);
            prob/=b;
        }
    }
}

void solve(int cs)
{

    int n,t,tar;
    vector<double> ans(100,0);
    vector<pair<int,double>> s[100];
    cin >> n >> t >> tar;
    for(int i=0;i<t;i++)
    {
        int a,b;double c;
        cin >> a >> b >> c;
        s[a].push_back({b,c});
    }

    dfs(1,n,tar,1.0,s,ans);

    int node = -1;
    double max_p = 0.0;
    for(int i=1;i<=n;i++)
    {
        if(max_p < ans[i])
        {
            max_p = ans[i];
            node=i;
        }
    }
    
    // cout << node << " " << max_p << "\n";
    printf("%d %0.6f\n",node,max_p);
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
