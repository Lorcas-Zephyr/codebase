#include<bits/stdc++.h>
#define int long long
const int Mod = 998244353;
using namespace std;
int p[60];
int pp[60][60];
int f[60];
bool cmp(int x, int y)
{
    return x > y;
}
void P(int x)
{
    p[1] = 1;
    for(int i = 2; i <= x; i++)
        p[i] = (p[i - 1] * i) % Mod;
    return ;
}
int pow(int a, int b)
{
    if(a == 1) return 2;
    int res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % Mod;
        a = (a * a) % Mod;
        b >>= 1;
    }
    return res;
}
int C(int n, int m)
{
    if(m > n) return 0;
    return (p[n] * pow((p[m] * p[n - m]) % Mod, Mod - 2)) % Mod;
}
void pre() {
    pp[0][0]=1ll;
    for(int i=1;i<=50;i++){
        pp[i][i]=1;
        for(int j=i-1;j>=0;j--)pp[i][j]=(pp[i][j+1]*(j+1))%Mod;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    pre();
    P(50);
    // for(int i = 1; i <= 50; i++) cout << p[i] << " ";
    p[0] = 1;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 0; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end(), cmp);
        int sum = 0;
        int cnt = 1;
        for(int i = 2; i <= n; i++)
            if(a[i] == a[1]) cnt++;
        for(int i = cnt + 1; i <= n; i++) sum += a[1] - 1 - a[i];
        if(sum > a[0])
        {
            cout << 0 << endl;
            continue;
        }
        int sum1 = 1;
        for(int i = 1; i <= min(a[0] - sum, n - cnt); i++)
        {
            // cout << pow(i + 1, cnt) << " ";
            for(int j = 1; j <= min(i + 1, cnt); j++)
            {
                //sum1 = (sum1 - (p[cnt] * pow(Mod - 1, j) % Mod * p[j] % Mod * p[cnt - j] % Mod * pow(i + 1 - j, cnt - j) % Mod) % Mod + Mod) % Mod;
                // cout << C(i + 1, j) << " ";
                // cout << pp[i + 1][j] << " ";
                sum1 = (sum1 + pp[i + 1][j]) % Mod;
            }
            sum1 = (sum1 + Mod - 1) % Mod;
        }
        cout << ((sum1 * p[n - cnt]) % Mod) * p[cnt] % Mod << endl;
    }
    return 0;
}