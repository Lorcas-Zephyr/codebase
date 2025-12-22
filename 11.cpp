#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> pos(n+1); // position of each number in permutation
        
        for(int i = 0; i < n; i++){
            cin >> p[i];
            pos[p[i]] = i;
        }
        
        // Check if we can form a valid tree
        // Key idea: for each vertex in order of permutation,
        // it should be able to connect to at least one smaller vertex
        // that appeared before it
        
        bool valid = true;
        for(int i = 1; i < n; i++){
            int curr = p[i];
            bool canConnect = false;
            
            // Check if there's any vertex smaller than curr
            // that appears before curr in permutation
            for(int j = 0; j < i; j++){
                if(p[j] < curr){
                    canConnect = true;
                    break;
                }
            }
            
            if(!canConnect){
                valid = false;
                break;
            }
        }
        
        cout << (valid ? "Yes" : "No") << "\n";
    }
    
    return 0;
}