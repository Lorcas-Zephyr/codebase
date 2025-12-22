#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char ch = getchar();
    string s = "";
    while(ch != '.')
    {
        s += ch;
        ch = getchar();
    }
    cout << s;
    return 0;
}