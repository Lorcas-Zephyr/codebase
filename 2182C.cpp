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
        int n;
        cin >> n;
        vector<int> a(3 * n + 1), b(3 * n + 1), c(3 * n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i], a[i + n + n] = a[i];
        for(int i = 1; i <= n; i++) cin >> b[i], b[i + n] = b[i], b[i + n + n] = b[i];
        for(int i = 1; i <= n; i++) cin >> c[i], c[i + n] = c[i], c[i + n + n] = c[i];
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(b[i] > a[1])
            {
                bool t = 1;
                for(int j = i + 1; j <= n + i - 1; j++)
                    if(b[j] <= a[j - i + 1])
                    {
                        t = 0;
                        break;
                    }
                if(t) ans1++;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(c[i] > b[1])
            {
                bool t = 1;
                for(int j = i + 1; j <= n + i - 1; j++)
                {
                    // cout << i << ' ' << c[j] << ' ' << b[j - i + 1] << '\n';
                    if(c[j] <= b[j - i + 1])
                    {
                        t = 0;
                        break;
                    }
                }
                if(t) ans2++;
            }
        }
        // cout << ans1 << ' ' << ans2 << '\n';
        cout << ans1 * ans2 * n << '\n';
    }
    return 0;
}