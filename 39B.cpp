#include<bits/stdc++.h>
using namespace std;
int dic[5][9] = {1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,0,0,1,1,1,1,1,0,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0};
bool b[100010];
int a[300][300];
int main()
{
    int n, L;
    cin >> n >> L;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n - 4; i++)
        for(int j = 1; j <= n - 8; j++)
        {
            int maxx = 0,minn = 1e6;
            for(int ii = 0; ii <= 4; ii++)
                for(int jj = 0; jj <= 8; jj++)
                    if(dic[ii][jj]) minn = min(minn, a[i + ii][j + jj]);
                    else maxx = max(maxx, a[i + ii][j + jj]);
            for(int ii = maxx + 1; ii <= minn; ii++) b[ii] = 1;
            // cout << maxx << minn << endl;
        }
    for(int i = 1; i <= L; i++)
        if(b[i]) cout << i << endl;
    return 0;
}