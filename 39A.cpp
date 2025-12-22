#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        double x, y;
        cin >> x >> y;
        if(x * x + y * y <= n * n) cnt ++;
    }
    cout << 4.0 * cnt / m << endl;
    return 0;
}