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
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        vector<int> p(n + 1);
        cin >> s;
        for(int i = 1; i <= n; i++) cin >> p[i];
        s = ' ' + s;
        vector<int> a(n + 1, 0);
        vector<int> b(n + 1, 0);
        int sum = 0;
        int sum1 = 0, sum2 = 0;
        bool t1 = 0, t2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '0')
            {
                a[i] = (p[i] + 2) / 2;
                b[i] = p[i] - a[i];
                sum1 += a[i];
                sum2 += b[i];
                t1 = 1;
            }else
            {
                b[i] = (p[i] + 2) / 2;
                a[i] = p[i] - b[i];
                sum1 += a[i];
                sum2 += b[i];
                t2 = 1;
            }
        }
        // cout << T << ' ' << t1 << ' ' << t2 << '\n';
        if(sum1 > x || sum2 > y)
        {
            cout << "NO\n";
            continue;
        }
        if(t1 && t2)
            if(sum1 <= x && sum2 <= y)
                cout << "YES\n";
            else ;
        else
        {
            int cnt = 0;
            for(int i = 1; i <= n; i++)
                cnt += p[i] % 2;
            if(t1)
            {
                int s1 = x - sum1;
                int s2 = y - sum2 - cnt;
                // cout << s1 << ' ' << s2 << '\n';
                if(s1 >= s2)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }else
            {
                int s1 = x - sum1 - cnt;
                int s2 = y - sum2;
                if(s2 >= s1)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}