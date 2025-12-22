#include<bits/stdc++.h>
using namespace std;
bool a[110][110];
int dic[8][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
struct Node
{
    int x, y ,st;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    queue<Node> q;
    q.push({ x, y, 0 });
    a[x][y] = 1;
    while(!q.empty())
    {
        auto t = q.front();
        if (t.st == m) break;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = t.x + dic[i][0];
            int ny = t.y + dic[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !a[nx][ny])
            {
                a[nx][ny] = 1;
                q.push({ nx, ny, t.st + 1 });
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j]) ans++;
    cout << ans << '\n';
    return 0;
}