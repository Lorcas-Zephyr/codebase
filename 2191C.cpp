/*
 * Author: Lorcas-Zephyr
 * Created: 2026-01-17
 * Contest: Codeforces
 * Problem: C. Sorting Game
 * URL: https://codeforces.com/contest/2191/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#define int long long
#define vi vector<int>

void solve() 
{
    int n;
    cin>>n;
    vi a(n+1);
    char c;
    for(int i=1;i<=n;i++) cin>>c,a[i]=c-'0';
    int sum1=0;
    for(int i=1;i<=n;i++) sum1+=a[i];
    if(sum1==0||sum1==n)
    {
        cout<<"Bob"<<endl;
        return;
    }
    int ans=-1;
    int sum0=n-sum1,sum2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)sum2++;
        else sum0--;
        if(sum0==sum2)
        {
            ans=i;
            break;
        }
    }
    if(sum0==0)
    {
        cout<<"Bob"<<endl;
        return;
    }
    cout<<"Alice"<<endl;
    cout<<sum0*2<<endl;
    for(int i=1;i<=ans;i++)
        if(a[i]==1)cout<<i<<" ";
    for(int i=ans+1;i<=n;i++)
        if(a[i]==0)cout<<i<<" ";
    cout<<endl;
    return;
}

signed main() 
{
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}