#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 300010;
int a[MAX_N];
int unique_nums[MAX_N];
int counts[MAX_N];


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
	    cin >> n;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    
	    // 如果只有一个元素，直接返回0
	    if (n == 1) {
	        cout << "0\n";
	        continue;
	    }
	    memset(unique_nums,0,sizeof(unique_nums));
	    memset(counts,0,sizeof(counts));
	    // 排序数组
	    sort(a, a + n);
	    
	    int removals = 0;
	    int unique_count = 0;
	    
	    // 统计每个不同数字的出现次数
	    int current_num = a[0];
	    int current_count = 1;
	    
	    for (int i = 1; i < n; i++) {
	        if (a[i] == current_num) {
	            current_count++;
	        } else {
	            unique_nums[unique_count] = current_num;
	            counts[unique_count] = current_count;
	            unique_count++;
	            
	            current_num = a[i];
	            current_count = 1;
	        }
	    }
	    // 添加最后一个数字
	    unique_nums[unique_count] = current_num;
	    counts[unique_count] = current_count;
	    unique_count++;
	    
	    // 计算需要删除的数量
	    for (int i = 1; i < unique_count; i++) {
	        // 如果当前数字与前一个数字连续
	        if (unique_nums[i] == unique_nums[i-1] + 1) {
	            // 如果当前数字的出现次数大于前一个数字的出现次数
	            if (counts[i] > counts[i-1]) {
	                removals += (counts[i] - counts[i-1]);
	            }
	        }
	    }
	    
	    cout << removals << "\n";
    }
    
    return 0;
}
