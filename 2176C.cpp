#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
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
        vector<int> a(1);
        vector<int> b(1);
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if(x % 2 == 1) a.push_back(x);
            else b.push_back(x);
        }
        sort(a.begin() + 1, a.end(), cmp);
        sort(b.begin() + 1, b.end(), cmp);
        vector<int> ans(1);
        if(a.size() > 1)
        {
            ans.push_back(a[1]);
            for(int i = 1; i < b.size(); i++)
                ans.push_back(ans[i] + b[i]);
            for(int i = 2; i < a.size(); i++)
                ans.push_back(ans[b.size() + i - 3]);
            if(a.size() % 2 == 1) ans[n] = 0;
        }
        else
            for(int i = 1; i <= n; i++) ans.push_back(0);
        for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0; 
}