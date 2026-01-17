/*
 * Author: Lorcas-Zephyr
 * Created: 2026-01-17
 * Contest: Codeforces
 * Problem: A. Array Coloring
 * URL: https://codeforces.com/contest/2191/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#define int long long
#define vi vector<int>

struct Node
{
    int v,c;
};
void solve() 
{
    int n;
    cin >> n;
    vector<Node> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i].v;
    for(int i=2;i<=n;i++) a[i].c=1-a[i-1].c;
    sort(a.begin()+1,a.end(),[](Node &x,Node &y){
        return x.v<y.v;
    });
    bool f=0;
    for(int i=2;i<=n;i++)
        if(a[i].c==a[i-1].c)
            f=1;
    if(f) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main() 
{
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}