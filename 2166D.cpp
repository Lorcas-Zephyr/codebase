#include<bits/stdc++.h>
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
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        vector<int> f(n + 1);
        f[0] = 1;
        int maxx = 0;
        for(int i = 1; i <= n; i++)
        {
            maxx = max(maxx, a[i]);
            if(a[i] == 0) continue;
            for(int j = n; j >= a[i]; j--)
            {
                f[j] = (f[j] + f[j - a[i]] * a[i]) % Mod;
            }   
        }
        int ans = 0;
        for(int i = maxx; i <= n; i++)
        {
            ans = (ans + f[i]) % Mod;
        }
        cout << ans << '\n';
    }
    return 0;
}