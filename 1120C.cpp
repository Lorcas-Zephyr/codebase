#include<bits/stdc++.h>
#define int long long
const int Mod = 998244353;
using namespace std;
int a[40];
void init()
{
    a[1] = 1;
    int id = 1;
    while(a[id] <= 4e6)
    {
        a[id + 1] = a[id] * 2;
        id++;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while(T--)
    {
        int l, r;
        cin >> l >> r;
        int id = 1;
        int id1 = 1;
        while(a[id] * l <= r) id++;
        // while(b[id1] * l <= r) id1++;
        cout << id -1 << ' ';
        int ans = 0;
        int pow = a[id - 1];
        ans += (r - l * pow) / pow + 1;
        ans += max(0LL, (id -2 ) * (r / (pow * 3 / 2) - l + 1));
        cout << ans << '\n';
    }
    return 0;
}