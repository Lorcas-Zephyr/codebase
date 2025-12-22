#include<bits/stdc++.h>
using namespace std;
int sum1[65], sum2[65];
int fun1(int x)
{
    int res = 0;
    while(x)
    {
        res++;
        if(x % 2 == 1) sum1[res]++;
        x /= 2;
    }
    return res;
}
int fun2(int x)
{
    int res = 0;
    while(x)
    {
        res++;
        if(x % 2 == 1) sum2[res]++;
        x /= 2;
    }
    return res;
}
void ch1(int x, int v)
{
    int res = 0;
    while(x)
    {
        res++;
        if(x % 2 == 1) sum1[res] += v;
        x /= 2;
    }
}
void ch2(int x, int v)
{
    int res = 0;
    while(x)
    {
        res++;
        if(x % 2 == 1) sum2[res] += v;
        x /= 2;
    }
}
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
        vector<int> a(n + 1), b(n + 1);
        vector<int> a1(n + 1), b1(n + 1);
        for(int i = 1; i <= n; i++) cin >> a1[i];
        for(int i = 1; i <= n; i++) cin >> b1[i];
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        int maxx = -1;
        for(int i = 1; i <= n; i++)
        {
            a[i] = fun1(a1[i]);
            b[i] = fun2(b1[i]);
            cout << a[i] << ' ' << b[i] << '\n';
            maxx = max(maxx, max(a[i], b[i]));
        }
        for(int i = 1; i <= n; i++)
        {
            if(i % 2 == 1)
            {
                if(a[i] > b[i])
                    if(sum1[a[i]] % 2 == 0) ch1(a1[i], -1), ch1(b1[i], 1) ,ch2(a1[i], 1), ch2(b1[i], -1);
                if(a[i] < b[i])
                    if(sum1[b[i]] % 2 == 0) ch1(a1[i], -1), ch1(b1[i], 1) ,ch2(a1[i], 1), ch2(b1[i], -1);

            }
            if(i % 2 == 0)
            {
                if(a[i] < b[i])
                    if(sum2[b[i]] % 2 == 0) ch1(a1[i], -1), ch1(b1[i], 1) ,ch2(a1[i], 1), ch2(b1[i], -1);
                if(a[i] > b[i])
                    if(sum2[a[i]] % 2 == 0) ch1(a1[i], -1), ch1(b1[i], 1) ,ch2(a1[i], 1), ch2(b1[i], -1);
            }
        }
        for(int i = maxx; i >= 0; i--)
        {
            sum1[i] = (sum1[i] % 2 + 2) % 2;
            sum2[i] = (sum2[i] % 2 + 2) % 2;
            cout << sum1[i] << ' ' << sum2[i] << '\n';
            if(sum1[i] > sum2[i])
            {
                cout << "Ajisai\n";
                break;
            }else if(sum1[i] < sum2[i])
            {
                cout << "Mai\n";
                break;
            }
            if(i == 0) cout << "Tie\n";
        }
    }
    return 0;
}