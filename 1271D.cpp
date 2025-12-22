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
        cin>>n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin>>a[i];
        if(n == 1)
        {
            cout<<"YES\n";
            continue;
        }
        int minn = a[1];
        vector<bool> b(n + 1);
        b[1] = 1;
        int pos1 = 1,pos2 = 1;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] > minn)
                b[i] = 1;
            if(a[i] == 1) pos1 = i;
            if(a[i] == n) pos2 = i;
            // cout << = i << ' ' << b[i] << ' ' << minn << '\n';
        }
        minn = a[1];
        for(int i = 1; i <= pos2; i++) b[i] = 1, minn = min(minn, a[i]);
        for(int i = pos2 + 1; i <= n; i++)
            if(a[i] > minn)
                b[i] = 1;
        int maxx = -1;
        for(int i = n; i >= pos2; i--)
            if(a[i] < maxx)
                b[i] = 1;
            else if (b[i] == 1)
                maxx = a[i];
        if(!b[pos1] && !b[pos2] )
        {
            cout<<"NO\n";
            continue;
        }
        if(b[pos1] && b[pos2])
        {
            if(pos1 < pos2)
            {
                cout<<"YES\n";
                continue;
            }
            else
            {
                bool flag = 1;
                for(int i = pos1; i <= pos2; i++)
                {
                    if(!b[i])
                    {
                        cout<<"NO\n";
                        flag = 0;
                        break;
                    }
                }
                if(flag) cout<<"YES\n";
            }
            continue;
        }
        if(b[pos1] == 0)
        {
            bool flag = 1;
            for(int i = pos2; i <= n; i++)
            {
                if(!b[i])
                {
                    cout<<"NO\n";
                    flag = 0;
                    break;
                }
            }
            if(flag) cout<<"YES\n";
            continue;
        }
    }
    return 0;
}