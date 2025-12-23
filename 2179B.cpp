#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 3);
        for(int i = 2; i <= n + 1; i++) cin >> a[i];
        a[n + 2] = a[n];
        vector<int> cha(n + 2);
        for(int i = 2; i < n + 1; i++) cha[i] = abs(a[i + 1] - a[i]);
        vector<int> sum(n + 2);
        for(int i = 2; i <= n; i++) sum[i] = sum[i - 1] + cha[i];
        sum[n + 1] = sum[n];
        int ans = 1e9;
        a[1] = a[3];
        for(int i = 2; i <= n + 1; i++)
        {
            int s = sum[i - 2] + sum[n] - sum[i] + abs(a[i + 1] - a[i - 1]);
            ans = min(ans, s);
            // cout << sum[i - 2] << " " << sum[n] - sum[i] << " " << a[i + 1] - a[i - 1] << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}