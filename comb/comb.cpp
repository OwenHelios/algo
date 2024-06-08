#include <bits/stdc++.h>
using namespace std;

// m <= n
int A(int n, int m) {
    int res = 1;
    while (m--) {
        res *= n--;
    }
    return res;
}

// m <= n
int C(int n, int m) {
    int res = 1;
    for (int i = 1; i <= m; ++i) {
        res *= n--;
        res /= i;
    }
    return res;
}

int main(){
    cout << C(7,3) << endl;
    return 0;
}
// g++ .\algos\comb\comb.cpp -o main;.\main