#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 10;
int n;
int a[MAXN], b[MAXN], c[MAXN];
int cnt[MAXN];
int d[MAXN][MAXN];
int m[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n)
    {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= 2 * n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i = 1; i <= n; i++) cnt[i] /= 2;
        int cn = 0, cn1 = 0;
        int ans = 0;
        for(int i = 1; i <= 2 * n; i++)
        {
            ans += cn1;
            if(cnt[a[i]] > 0)
            {
                cnt[a[i]]--;
                b[++cn] = a[i];
            }else
            {
                c[++cn1] = a[i];
            }
            if(cn == n) break;
        }
        // cout << "Debug: cn = " << cn << ", cn1 = " << cn1 << endl; // Debug line
        for(int i = cn1 + cn + 1; i <= 2 * n; i++)
        {
            c[++cn1] = a[i];
            // cout << a[i] << ' '; // Debug line
        }
        int tot = 0;
        // for(int i = 1; i <= n; i++)
        //     cout << b[i] << " ";   // Debug line
        // cout << "Debug: ans = " << ans << endl; // Debug line
        memset(d, 0, sizeof(d));
        // for(int i = 1; i <= n; i++) 
        //     cout << c[i] << " ";   // Debug line
        for(int i = 1; i <= n; i++)
        {
            d[b[i]][0]++;
            d[b[i]][d[b[i]][0]] = i;
            b[i] = i;
        }
        for(int i = 1; i <= n; i++)
            d[i][0] = 0;
            // if(d[b[i]] == 0) d[b[i]] = ++tot;
        for(int i = 1; i <= n; i++)
        {
            // cout << "Debug: c[" << i << "] before = " << c[i] << endl; // Debug line
            // cout << "Debug: d[c[" << i << "]] = " << d[c[i]][1] << endl; // Debug line
            // cout << "Debug: d[c[" << i << "]][0] = " << d[c[i]][0] << endl; // Debug line
            // cout << "Debug: c[" << i << "] after = " << d[c[i]][d[c[i]][0]] << endl; // Debug line
            d[c[i]][0]++;
            c[i] = d[c[i]][d[c[i]][0]];
        }
            // c[i] = d[c[i]];
        // for(int i = 1; i <= n; i++) 
        //     cout << c[i] << " ";   // Debug line
        // for(int i = 1; i < n; i++)
        // {
        //     bool flag = true;
        //     for(int j = n; j > i; j--)
        //         if(c[j] < c[j - 1])
        //         {
        //             flag = false;
        //             swap(c[j], c[j - 1]);
        //             ans++;
        //         }
        //     if(flag) break;
        // }
        for(int i = 1; i <= n; i++)
            m[b[i]] = i;
        int ans2 = 0;
        for(int i = 1; i <= n; i++)
            ans2 += abs(i - m[c[i]]);
        // for(int i = 1; i <= n; i++)
        //     cout << m[c[i]] << ' ';
        // cout << endl;
        cout << ans + ans2 / 2 << endl;
        cin >> n;
    }
    return 0;
}