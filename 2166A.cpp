#include<bits/stdc++.h>
using namespace std;
int T, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        char s[105];
        cin >> s;
        int ans = 0;
        for(int i = n - 2; i >= 0; i--)
        {
            if(s[i] != s[i + 1])
            {
                ans++;
                s[i] = s[i + 1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}