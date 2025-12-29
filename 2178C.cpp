#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        int t = 0,f = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] < 0) t = 1;
            else f = 1;
        int sum = a[1], sum1 = 0, sum2 = 0;
        for(int i = 2; i <= n; i++)
            sum += abs(a[i]);
        int tt = 0, ttt = 0, cnt = 0;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] < 0) sum1 += abs(a[i]), tt = 0;
            else sum2 += abs(a[i]), tt = 1;
            ttt = tt;
            cnt += abs(ttt - tt);
        }
        if(ttt == 1)
        {
            if(a[1] < 0) 
            {
                int id = n;
                int sum3 = 0;
                while(a[id] >= 0 && id >= 1) sum3 += abs(a[id]), id--;
                sum3 = min(sum3, abs(a[1]));
                int sum4 = 0;

            }
        }
        // cout << sum << " ";
        int ans = 0;
        if(t + f == 1)
        {
            if(t) ans = sum - a[1];
            else ans = sum - a[n];
        }
        else
        {
            
            int id = n;
            int minn = 1e10;
            if(a[n] < 0) minn = -a[n], id = n - 1;
            while(a[id] < 0 && id >= 1) minn = min(minn, a[id]),id--;
            if(a[id] > 0) minn = min(minn, abs(a[id]));
            // if(a[1] < 0) minn = min(minn, abs(a[1]));
            // sum = sum - a[1] + abs(a[1]);
            cout << minn << " ";
            ans = sum - minn;
            
        }
        cout << ans << "\n";
    }
    return 0;
}