#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        int s = a / b;
        if(n <= s) cout << 1 << endl;
        else 
        {
            if(a == b) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0;
}