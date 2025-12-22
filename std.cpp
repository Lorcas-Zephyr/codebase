#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> numa(n + 1);
        vector<int> numb(n + 1);
        for (int a = 1; a <= n; a++)
        {
            cin >> numa[a];
        }
        for (int a = 1; a <= n; a++)
        {
            cin >> numb[a];
        }

        bool ok = false;
        unordered_map<int, int> mp, mp1;
        for (int a = 1; a <= n; a++)
        {
            if (numa[a] != numb[a])
            {
                ok = true;
                bitset<21> i, j;
                i = numa[a];
                j = numb[a];
                for (int h = 20; h >= 0; h--)
                {
                    if (i.test(h) != j.test(h))
                    {
                        mp[h]++;
                        if (a % 2 == 1)
                            mp1[h] = 1;
                        else
                            mp1[h] = 2;
                    }
                }
            }
        }

        if (!ok)
        {
            cout << "Tie" << '\n';
            continue;
        }
        bool t = false;
        for (int a = 50; a >= 0; a--)
        {
            if (!mp.count(a))
                continue;
            if (mp[a] % 2 == 1)
            {
                if (mp1[a] == 1)
                {
                    cout << "Ajisai" << '\n';
                    t = 1;
                    break;
                }
                else
                {
                    cout << "Mai" << '\n';
                    t = 1;
                    break;
                }
            }
        }
        if (!t)
            cout << "Tie" << '\n';
    }
}