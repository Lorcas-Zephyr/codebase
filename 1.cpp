#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> odd, even;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(x % 2 == 1) odd.push_back(x);
            else even.push_back(x);
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        
        vector<int> ans(n + 1, 0);
        
        if(odd.empty())
        {
            // 全是偶数，任何操作后都是偶数，得分为 0
            for(int k = 1; k <= n; k++)
                ans[k] = 0;
        }
        else
        {
            // 策略：先放最大奇数，然后交替放偶数和奇数
            vector<int> sequence;
            sequence.push_back(odd[0]);
            
            int oddIdx = 1, evenIdx = 0;
            while(oddIdx < (int)odd.size() || evenIdx < (int)even.size())
            {
                if(evenIdx < (int)even.size())
                    sequence.push_back(even[evenIdx++]);
                if(oddIdx < (int)odd.size())
                    sequence.push_back(odd[oddIdx++]);
            }
            
            // 模拟过程，计算每个 k 的答案
            int sum = 0;
            int seqIdx = 0;
            for(int k = 1; k <= n; k++)
            {
                if(seqIdx < (int)sequence.size())
                {
                    sum += sequence[seqIdx++];
                    
                    // 如果 sum 是偶数，包被清空
                    if(sum % 2 == 0)
                        sum = 0;
                }
                ans[k] = sum;
            }
        }
        
        for(int k = 1; k <= n; k++)
            cout << ans[k] << (k == n ? '\n' : ' ');
    }
    return 0;
}