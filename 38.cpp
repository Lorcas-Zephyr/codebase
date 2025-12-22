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
        long double n, miu, rou;
        cin >> miu >> rou >> n;
        long double z = (n - miu) * 10 / rou;
        int h = int(z) + 1;
        int l = int(z * 10) % 10 + 1;
        cout << h << ' ' << l << '\n';
    }
    return 0;
}