#include <bits/stdc++.h>

using namespace std;
#define i64 long long

void solve() {
    int n, k;
    cin >> n >> k;
    int lo = 1;
    int hi = k;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        hi = max(hi, a[i]+ k);
    }
    auto valid = [&](int target) {
        for (int i=0;i<n;++i) {
            int have = k;
            for (int j=i;j<n;++j) {
                int required = target - (j-i);
                if (a[j] >= required) {
                    return true;
                }
                int need = required - a[j];
                if (have < need) break;
                have -= need;
            }
        }
        return false;
    };
    // bisect right
    while(lo < hi) {
        int mid = (lo+hi+1)/2;
        if (valid(mid)) {
            lo = mid;
        } else{
            hi = mid - 1;
        }
    }
    cout << lo << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
