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
        int ans = 0;
        if(s[0] == 'u')
        {
            s[0] = 's';
            ans++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'u')
            {
                if((i + 1 < s.size() && s[i + 1] == 'u') || (i + 1 == s.size()))
                {
                    ans++;       
                    s[i + 1] = 's';       
                    // cout << i << ' ';
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}