/*
 * Author: Lorcas-Zephyr
 * Created: 2025-12-30
 * Contest: Codeforces
 * Problem: E. New Year's Gifts
 * URL: https://codeforces.com/contest/2182/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#define int long long
#define vi vector<int>

struct Node
{
    int x, y, z, odd;
    bool f = 0;
};

void solve() 
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<Node> b(n + 1);
    vi a(m + 1);
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i].x >> b[i].y >> b[i].z;
    for(int i = 1; i <= n; i++) b[i].odd = max(b[i].z - b[i].y, 0ll), k -= b[i].y;
    // cout << 1;
    sort(a.begin() + 1, a.end(), greater<int>());
    sort(b.begin() + 1, b.end(), [](const Node &p, const Node &q) {
        return p.odd > q.odd;
    });
    int id1 = 1, id2 = 1;
    int ans = 0;
    // cout << 1;
    while(id1 <= m && id2 <= n)
    {
        while(id2 <= n && a[id1] < b[id2].x) id2++;
        if(id2 > n) break;
        if(a[id1] >= b[id2].x)
        {
            // cout << id1 << " " << id2 << endl;
            b[id2].f = 1;
            ans++;
            id1++;
            id2++;
        } else break;
        // cout << id2 << endl;
    }
    // cout << id2 << endl;
    sort(b.begin() + 1, b.end(), [](const Node &p, const Node &q) {
        return p.odd < q.odd;
    });
    // cout << n << k << endl;
    cout << ans << " ";
    for(int i = 1; i <= n; i++)
    {
        // cout << b[i].f << " " << b[i].odd << endl;
        if(!b[i].f && k >= b[i].odd)
        {
            // cout << b[i].z << " ";
            k -= b[i].odd;
            ans++;
        }
    }
        
    cout << ans << endl;
}

signed main() 
{
    fastio;
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}