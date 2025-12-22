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
        vector<int> a(n + 1);
        int ans = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = n; i > 1; i--)
            for(int j = 1; j < i; j++)
                if(a[j] > a[i])
                {
                    ans++;
                    break;
                }
        cout << ans << endl;
    }
    return 0;
}