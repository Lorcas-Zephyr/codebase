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
        string s;
        cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == 'Y' )
                cnt++;
        if(cnt < 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}