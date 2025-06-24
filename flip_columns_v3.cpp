#include <iostream>
#include <unordered_map>
using namespace std;

void solve(int cs) {
    int n, m, k;
    cin >> n >> m >> k;
    
    unordered_map<int, int> dict;
    
    for (int i = 0; i < n; i++) {
        int zeros = 0;
        int rowMask = 0;
        
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x == 0) zeros++;
            rowMask = (rowMask << 1) | x;  // Build bitmask instead of string
            // cout << rowMask << endl;
        }
        
        if (zeros <= k && (k - zeros) % 2 == 0) {
            dict[rowMask]++;
        }
    }
    
    int ans = 0;
    for (auto [pattern, count] : dict) {
        ans = max(ans, count);
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1, cs = 1;
    while (t--) solve(cs++);
    return 0;
}