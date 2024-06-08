// https://codeforces.com/problemset/problem/148/A
#include <bits/stdc++.h>

using namespace std;

int lcm(int x, int y) {
    return x * y / __gcd(x, y);
}

int lcm(int x, int y, int z) {
    return lcm(x, lcm(y, z));
}

int lcm(int x, int y, int z, int a) {
    return lcm(x, lcm(y, z, a));
}
/*
A | B | C | D = +(A + B + C + D)
                -(A & B + B & C + ...)
                +(A & B & C + A & B & D + ...)
                -(A & B & C & D)
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    int e1 = n / a + n / b + n / c + n / d;
    int e2 = n / lcm(a, b) + n / lcm(a, c) + n / lcm(a, d) + n / lcm(b, c) + n / lcm(b, d) + n / lcm(c, d);
    int e3 = n / lcm(a, b, c) + n / lcm(a, b, d) + n / lcm(a, c, d) + n / lcm(b, c, d);
    int e4 = n / lcm(a, b, c, d);
    cout << e1 - e2 + e3 - e4 << '\n';
    return 0;
}