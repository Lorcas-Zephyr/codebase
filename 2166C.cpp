#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        int maxx = 0;
        for(int i = 0; i < n; i++) 
        {
            cin >> a[i];
            a[i + n] = a[i];
            maxx = max(maxx, a[i]);
        }
        if(n == 1)
        {
            cout << a[0] << "\n";
            continue;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int tot = 0;
            if(a[i-1] < a[i]) tot++;
            if(a[i] >= a[i+1]) tot++;
            ans += tot * a[i];
            // cout << tot << ' '; //DEBUG 4
        }
        cout << ans - maxx << "\n";
    }
    return 0;
}