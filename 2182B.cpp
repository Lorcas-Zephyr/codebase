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
        int x, y;
        cin >> x >> y;
        int sum[2] = {0, 0};
        int ans = 0, s = 1, id = 0;
        while(1)
        {
            sum[id] += s;
            if((sum[0] <= x && sum[1] <= y) || (sum[0] <= y && sum[1] <= x))
            {
                ans++;
                s *= 2;
                id ^= 1;
            }else break;
        }
        cout << ans << endl;
    }
    return 0;
}