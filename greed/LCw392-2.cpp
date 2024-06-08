// https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        for (int i = 0; i < n - 1; ++i) {
            if (i < n - 2 && binary.substr(i, 3) == "010") {
                binary[i] = '1';
                binary[i + 1] = '0';
                binary[i + 2] = '1';
            }
            if (binary.substr(i, 2) == "00") {
                binary[i] = '1';
            }
        }
        return binary;
    }
};

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (char &ch : s) {
            if (!k) break;
            int p1 = ch - 'a';
            int p2 = 'z' - ch + 1;
            if (p1 > p2 && k >= p2) {
                k -= p2;
                ch = 'a';
            } else {
                int price = min(p1, k);
                ch -= price;
                k -= price;
            }
        }
        return s;
    }
};