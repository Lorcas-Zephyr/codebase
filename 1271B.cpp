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
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(a[1] != -1 && a[n] != -1)
        {
            cout << abs(a[n] - a[1]) << "\n";
            for(int i = 1; i <= n; i++) 
                if(a[i] != -1) cout << a[i] << " ";
                else cout << 0 << ' ';
            cout << "\n";
        }else
        if(a[1] == -1 && a[n] == -1)
        {
            cout << 0 << "\n";
            for(int i = 1; i <= n; i++) 
                if(a[i] != -1) cout << a[i] << " ";
                else cout << 0 << ' ';
            cout << "\n";
        }else
        {
            if(a[1] == -1)
            {
                cout << 0 << "\n";
                a[1] = a[n];
                for(int i = 1; i <= n; i++) 
                    if(a[i] != -1) cout << a[i] << " ";
                    else cout << 0 << ' ';
                cout << "\n";
            }else
            {
                a[n] = a[1];
                cout << 0 << "\n";
                for(int i = 1; i <= n; i++) 
                    if(a[i] != -1) cout << a[i] << " ";
                    else cout << 0 << ' ';
                cout << "\n";
            }
        }
    }
    return 0;
}