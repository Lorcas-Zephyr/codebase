/*
 * Author: Lorcas-Zephyr
 * Created: 2026-01-04
 * Contest: Codeforces
 * Problem: L. Subsequence
 * URL: https://codeforces.com/gym/105901/problem/L
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#define int long long
#define vi vector<int>
int n, a[3010];

int find(int x)
{
    int l = 1, r = n;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] == x) l = mid + 1;
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    if(a[r] == x) return r;
    return -1;
}
void solve() 
{
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        for(int j = n; j >= i; j--)
        {
            int t = find(a[j] * 2 - a[i]);
            if(t > 0)
            {
                // cout << i << " " << j << " " << t << " : " << endl;
                int ii = i;
                // while((ii + t) / 2 < j) ii++;
                // while((ii + t) / 2 > j) t--;
                // ans = max(ans, t - ii + 1);
                int ans1 = min(j - i, t - j) * 2 + 1;
                int ans2 = min(j - i + 1, t - j) * 2;
                ans = max(ans, min(max(ans1, ans2), t - i + 1));

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