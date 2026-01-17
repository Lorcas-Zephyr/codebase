#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), freq(n+1, 0);
        for (int i = 0; i < n; ++i) { cin >> a[i]; if (a[i] <= n) ++freq[a[i]]; }
        bool impossible = false;
        for (int v = 0; v <= n; ++v) {
            if (freq[v] == 0) {
                bool allLessAtLeastTwo = true;
                for (int j = 0; j < v; ++j) if (freq[j] < 2) { allLessAtLeastTwo = false; break; }
                if (allLessAtLeastTwo) { impossible = true; break; }
            }
        }
        cout << (impossible ? "NO" : "YES") << '\n';
    }
    return 0;
}