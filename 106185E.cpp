#include<bits/stdc++.h>
const int MAXN = 1e3 + 10;
using namespace std;
int n, m[MAXN], s[MAXN], cnt1, v, tt, ans[MAXN];
bool b[MAXN];
struct Node
{
    int t, v;
}a[MAXN];
bool cmp(Node a, Node b)
{
    return a.t < b.t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n)
    {
        int maxx = 0;
        for(int i = 1; i < n; i++)
        {
            cin >> v >> tt;
            m[i + 1] = v;
            a[i].t = tt + 1;
            a[i].v = i + 1;
            maxx = max(maxx, tt + 1);
        }
        if(maxx < n - 1)
        {
            cout << "no\n";
            cin >> n;
            continue;
        }
        cnt1 = 0;
        sort(a + 1, a + n, cmp);
        // for(int i = 1; i <= n;)
        int id = 1;
        bool t = 0;
        // cnt = 0;
        memset(b, 0, sizeof(b) );
        b[1] = 1;
        int tm = 0;
        while(id < n)
        {
            int v = a[id].v;
            // int cnt1 = cnt;
            int cnt = 0;
            while(b[v] == 0)
            {
                s[++cnt] = v;
                b[v] = 1;
                v = m[v];
                // cout << v << ' '; //
            }
            // cout << cnt << endl; //
            // v = a[id].v;
            if(a[id].t >= tm + cnt)
            {
                tm += cnt;
                for(int i = cnt; i >= 1; i--) ans[++cnt1] = s[i];
            } else
            {
                t = 1;
                break;
            }
            id++;
            while(id < n && b[a[id].v] == 1) id++;
        }
        if(t) cout << "no\n";
        else 
        {
            cout << "yes\n";
            for(int i = 1; i <= cnt1; i++)
                cout << ans[i] << ' ';
            cout << endl;
        }
        cin >> n;
    }
    return 0;
}