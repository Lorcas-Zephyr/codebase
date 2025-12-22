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
        int ans = 0;
        for(int i = 0; i <= n / 4; i++)
            if((n - 4 * i) % 2 == 0)
                ans++;
        cout << ans << '\n';
    }
    return 0;
}