// https://codeforces.com/contest/1942/problem/B
#include <bits/stdc++.h>

// mex ("minimum excluded value")
/*
0 <= pi < n
m[i] = mex(p1,...,pi)
ai = m[i] - pi
1) m[i] > pi : m[i - 1] == pi
2) m[i] < pi : m[i - 1] == m[i]
*/
using namespace std;
void solve() {
    int n;
    vector<int> a(n);
    vector<int> mex(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mex[i + 1] = mex[i] + max(a[i], 0);
    }
    for (int i = 0; i < n; ++i) {
        cout << mex[i + 1] - a[i] << " \n"[i == n - 1];
    }
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