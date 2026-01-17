/*
 * Author: Lorcas-Zephyr
 * Created: 2026-01-17
 * Contest: Codeforces
 * Problem: B. MEX Reordering
 * URL: https://codeforces.com/contest/2191/problem/B
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
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(n+1,false);
    for(int i=1;i<=n;i++) b[a[i]]++;
    sort(a.begin()+1,a.end());
    int mex2=-1,mex1=-1;
    for(int i=0;i<=n;i++)
        if(!b[i])
        {
            mex2=i;
            break;
        }
    vector<bool> c(n+1,false);
    bool f=0;
    for(int i=1;i<n;i++)
    {
        if(i==1)
        {
            if(a[i]>0) mex1=0,c[0]=1;
            else mex1=1,c[1]=1;
        }
        else
        {
            if(a[i]==mex1)
            {
                c[a[i]]=1;
                mex1++;
                while(c[mex1]) mex1++;
            }
        }
        b[a[i]]--;
        if(b[a[i]]==0 && a[i]<mex2) mex2=a[i];
        if(mex1==mex2)
        {
            f=1;
            break;
        }
        // cout<<i<<' '<<mex1<<' '<<mex2<<endl;
    }
    if(f) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main() 
{
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}