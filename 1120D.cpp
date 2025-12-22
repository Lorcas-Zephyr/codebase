#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        // if(x < 0) k = n - k, x = -x;
        vector<long long> a(n + 2);
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(x >= 0)
        {
            int l = 1, r = 1;
            int sum = 0;
            int maxx = 0;
            while(r <= n)
            {
                sum += a[r];
                while(l <= r && ((a[l] <= x && r - l + 1 > k )|| sum + min(k, r - l + 1) * x - (r - l + 1 - min(k, r - l + 1)) * x < maxx || a[l] <= -x))
                {
                    sum -= a[l];
                    l++;
                }
                if(sum + min(k, r - l + 1) * x - (r - l + 1 - min(k, r - l + 1)) * x > maxx)
                {
                    maxx = sum + min(k, r - l + 1) * x - (r - l + 1 - min(k, r - l + 1)) * x;
                }     
                // cout << l << " " << r << " " << sum << ' ' << sum + min(k, r - l + 1) * x - (r - l + 1 - min(k, r - l + 1)) * x << "\n";
                // cout <<  min(k, r - l + 1) * x << ' ' << (r - l + 1 - min(k, r - l + 1)) * x << "\n";
                
                r++;
                //cout << l << " " << r << " " << sum + min(k, r - l + 1) * x - (r - l + 1 - min(k, r - l + 1)) * x << "\n";
            }
            cout << maxx << "\n";
        }
        else
        {
            for(int i = 1; i <= n; i++) a[i] -= x;
            int l = 1, r = 1;
            int sum = 0;
            int maxx = 0;
            while(r <= n)
            {
                sum += a[r];
                while(l <= r && a[l] < 0)
                {
                    sum -= a[l];
                    l++;
                }
                if(sum + 2 * min(k, r - l + 1) * x> maxx)
                {
                    maxx = sum + 2 * min(k, r - l + 1) * x;
                }     
                r++;
            }
            cout << maxx << "\n";
        }
    }
    return 0;
}