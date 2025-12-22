#include <bits/stdc++.h>
#define int long long
const int Mod = 998244353;
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
        vector<int> b(n + 1);
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            b[x]++;
        }

        int ans = 1;
        for(int i = 1; i <= n; i++)
            ans = ans * (b[i] + 1) % Mod;

        int maxx = 0;
        for(int i = 1; i <= n; i++) maxx = max(maxx, b[i]);
        int cntMax = 0;
        for(int i = 1; i <= n; i++) if(b[i] == maxx) cntMax++;

        if(cntMax >= 2)
        {
            // 如果存在不止一个值达到最大频次，则只需减去 1
            ans = (ans - 1) % Mod;
            if(ans < 0) ans += Mod;
        }
        else
        {
            // 唯一的最大频次数值，减去所有其他正频次的 (b[i]+1) 之和（若无其他则减 1）
            long long sub = 0;
            for(int i = 1; i <= n; i++)
                if(b[i] > 0 && b[i] != maxx)
                    sub = (sub + b[i] + 1) % Mod;
            if(sub == 0) sub = 1;
            ans = (ans - sub) % Mod;
            if(ans < 0) ans += Mod;
        }

        cout << ans << '\n';
    }
    return 0;
}
