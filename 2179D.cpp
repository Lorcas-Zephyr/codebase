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
        int x = 1;
        for(int i = 0; i < n; i++) x *= 2;
        vector<bool> used(x, false);
        n = x;
        if(n == 2)
        {
            cout << "1 0\n";
            continue;
        }
        while(x > 1)
        {
            for(int i = (n - 1) % x; i < n; i += x)
                if(!used[i])
                {
                    cout << i << ' ';
                    used[i] = true;
                }
            x /= 2;
        }
        for(int i = 0; i < n; i++)
            if(!used[i])
                cout << i << ' ';
        cout << '\n';
    }
    return 0;
}