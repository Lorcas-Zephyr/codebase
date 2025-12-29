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
        string s;
        cin >> n;
        cin >> s;
        bool t1 = 0, t2 = 0;
        if(n < 4)
        {
            cout << 0 << endl;
            continue;
        }
        for(int i = 0; i < n - 3; i++)
        {
            if(s.substr(i, 4) == "2025")
            {
                t1 = 1;
            }
            if(s.substr(i, 4) == "2026")
            {
                t2 = 1;
            }
        }
        if(!t1 || t2) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}