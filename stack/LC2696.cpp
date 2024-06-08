#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char ch: s) {
            if (st.empty()) {
                st.push(ch);
                continue;
            }
            char t = st.top();
            if (t=='A' && ch == 'B' || t=='C' && ch=='D') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.size();
    }
};