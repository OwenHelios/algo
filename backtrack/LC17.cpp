#include <bits/stdc++.h>
using namespace std;

// push and pop
class Solution {
public:
    vector<string> arr = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;
        int n = digits.size();
        function<void(int)> dfs = [&](int i) {
            if (i==n) {
                ans.push_back(cur);
                return;
            }
            for (char ch: arr[digits[i] - '2']) {
                cur.push_back(ch);
                dfs(i+1);
                cur.pop_back();
            }
        };
        if(n) dfs(0);
        return ans;
    }
};

// no push or pop
class Solution {
public:
    vector<string> arr = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;
        int n = digits.size();
        cur.resize(n);
        function<void(int)> dfs = [&](int i) {
            if (i==n) {
                ans.push_back(cur);
                return;
            }
            for (char ch: arr[digits[i] - '2']) {
                cur[i] = ch;
                dfs(i+1);
            }
        };
        if(n) dfs(0);
        return ans;
    }
};

// iteration
class Solution {
public:
    vector<string> arr = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if (!n) return ans;
        ans.push_back("");
        for(char d: digits) {
            vector<string> tmp;
            for (string s: ans) {
                for (char ch: arr[d-'2']) {
                    tmp.push_back(s+ch);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};