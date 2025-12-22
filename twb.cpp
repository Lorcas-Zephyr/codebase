#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)  cin >> b[i];
    vector<int> a(1);
    int s = 0;
    for(int i = 1; i <= n; i++)
    {
        if((s < 0 && b[i] > 0 ) || (s > 0 && b[i] < 0)) a.push_back(s), s = b[i];
        else s += b[i];
        // cout << "i: " << i << " s: " << s << endl; // Debug line, can be removed
    }
    a.push_back(s);
    n = a.size() - 1;
    if(n == 1)
    {
        if(a[1] > 0) cout << a[1] * 2 << endl;
        else cout << abs(a[1]) << endl;
        return 0;
    }
    int maxx = 0, maxid = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] > maxx) maxx = a[i], maxid = i;
    // cout << maxid << endl; // Debug line, can be removed
    vector<int> sum1(n + 1);
    vector<int> sum2(n + 1);
    for(int i = 1; i <= n; i++)
        sum1[i] = sum1[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
        sum2[i] = sum2[i - 1] + abs(a[i]);
    int l = maxid;
    for(int i = maxid - 2; i >= 1; i-=2)
    {
        int s1 = sum1[maxid - 1] - sum1[i - 1];
        int s2 = sum2[maxid - 1] - sum2[i - 1];
        if(s1 * 2 < s2) break;
        l = i;
    }
    int r = maxid;
    for(int i = maxid + 2; i <= n; i+=2)
    {
        int s1 = sum1[i] - sum1[maxid];
        int s2 = sum2[i] - sum2[maxid];
        if(s1 * 2 < s2) break;
        r = i;
    }
    // cout << l << " " << r << endl; // Debug line, can be removed
    int ans = sum2[l - 1] + sum2[n] - sum2[r] + 2 * (sum1[r] - sum1[l - 1]);
    cout << ans << endl;
}