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
        string s;
        cin >> s;
        string s2 = s + s;
        int cnt = 0;
        int maxx = 0;
        for(int i = 0; i < s2.size(); i++)
            if(s2[i] == '0') cnt++;
            else
            {
                maxx = max(maxx, cnt);
                cnt = 0;
            }
        cout << maxx << endl;
    }
    return 0;
}