#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        int n1 = s1.length();
        int n2 = s2.length();
        int maxx = 0;
        int maxl1 = -1, maxr1 = -1, maxl2 = -1, maxr2 = -1;
        for(int i = 0; i < n1; i++)
        {
            for(int j = 0; j < n2; j++)
                if(s1[i] == s2[j])
                {
                    int id = 0;
                    int xb = 0;
                    int cnt = 0;
                    if(i == 0 && j == 0) cnt++;
                    while(id + i < n1 && id + j < n2 && s1[id + i] == s2[id + j]) id++;
                    if(id + i == n1 && id + j == n2) cnt++;
                    cnt += id - xb;
                    if(cnt >= maxx) 
                    {
                        maxx = cnt;
                        maxl1 = xb + i;
                        maxr1 = id + i - 1;
                        maxl2 = xb + j;
                        maxr2 = id + j - 1;
                    }
                }
        }
        if(maxx >= 2)
        {
            cout << "YES" << endl;
            if (maxl1 > 0 || maxl2 > 0)
            {
                cout << "*";
            }
            for(int i = maxl1; i <= maxr1; i++)
            {
                cout << s1[i];
            }
            if(maxr1 < n1-1 || maxr2 < n2-1)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}