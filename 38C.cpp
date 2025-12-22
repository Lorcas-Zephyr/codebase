#include<bits/stdc++.h>
#define int long long
const int Mod = 998244353;
using namespace std;
int pow(int x, int y)
{
    int res = 1;
    while(y)
    {
        if(y & 1) res = res * x % Mod;
        x = x * x % Mod;
        y >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 2);
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    a[0] = 0;
    a[m + 1] = n + 1;
    vector<int> b(m + 2);
    for(int i = m + 1; i >= 1; i--)
        b[i] = a[i] - a[i - 1] - 1;
    vector<int> c(m + 3);
    for(int i = m + 1; i >= 1; i--)
    {
        c[i] += c[i + 1];
        if(b[i] > 5) c[i] += b[i] - 5;
    }
    int k = pow(26, n - m - 9);
    int ans = 0;
    int k1 = 1;
    int sum = 1;
    for(int i = 1; i <= m + 1; i++)
    {
        if(b[i] > 2) ans = (ans + (b[i] - 2) * (k / sum * k1 ) * c[i + 1]) % Mod,
                    k1 = (k1 * (pow(26, b[i] - 3) * ((b[i] - 2) * ( pow(26, 3) - 1))) ),
                    k1 %= Mod;
        if(b[i] > 8) ans = (ans + (b[i] - 8) * (b[i] - 7) / 2 % Mod * k) % Mod;
        sum = (sum * pow(26, b[i]));
        sum %= Mod;
        // cout << ans << ' ' << k << ' ' << sum << ' ' << k1 << endl;
    }
    cout << ans << '\n';
    return 0;
}