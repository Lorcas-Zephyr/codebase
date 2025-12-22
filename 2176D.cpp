#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998345353;

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2)
{
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second;
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<pair<int,int>> E(m);
        vector<vector<pair<int,int>>> edge(n+1);
        for (int i = 0; i < m; ++i) 
        {
            int v,u;
            cin >> v >> u; 
            E[i] = {v,u};
            edge[v].push_back({a[u], i});
        }
        for (int v = 1; v <= n; ++v) 
        {
            sort(edge[v].begin(), edge[v].end(),cmp);
        }
        vector<int> f(m, -1);
        function<int(int)> dfs = [&](int id)->int
        {
            if (f[id] != -1) return f[id];
            //cout << "dfs(" << id << ")\n";
            int u = E[id].first;
            int v = E[id].second;
            int sum = a[u] + a[v];
            auto &vec = edge[v];
            pair<int,int> keyL = {sum, numeric_limits<int>::min()};
            pair<int,int> keyR = {sum, numeric_limits<int>::max()};
            auto itL = lower_bound(vec.begin(), vec.end(), keyL,
                                   [](const pair<int,int>& p, const pair<int,int>& q)
                                   {
                                       if (p.first != q.first) return p.first < q.first;
                                       return p.second < q.second;
                                   });
            auto itR = upper_bound(vec.begin(), vec.end(), keyR,
                                   [](const pair<int,int>& q, const pair<int,int>& p)
                                   {
                                       if (q.first != p.first) return q.first < p.first;
                                       return q.second < p.second;
                                   });
            int res = 1;
            for (auto it = itL; it != itR; ++it)
             {
                int id2 = it->second;
                res += dfs(id2);
                if (res >= MOD) res -= MOD;
            }
            f[id] = res % MOD;
            //cout << "f[" << id << "] = " << f[id] << '\n';
            return f[id];
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += dfs(i);
            if (ans >= MOD) ans -= MOD;
            // cout << "dfs(" << i << ") = " << dfs(i) << '\n';
        }
        cout << ans % MOD << '\n';
    }
    return 0;
}