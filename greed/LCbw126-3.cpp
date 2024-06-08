// https://leetcode.cn/problems/replace-question-marks-in-string-to-minimize-its-value/
#include <bits/stdc++.h>

using namespace std;

// heap
class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        int m = 0;
        for (char &ch : s) {
            if (ch != '?') {
                freq[ch - 'a']++;
            } else {
                m++;
            }
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> q;
        for (int i = 0; i < 26; ++i) {
            q.emplace(freq[i], 'a' + i);
        }
        string t(m, 0);
        for (int i = 0; i < m; ++i) {
            auto [f, ch] = q.top();
            q.pop();
            t[i] = ch;
            q.emplace(f + 1, ch);
        }
        // the order in which slots are filled doesn't change cost, only changes lexicographical order
        sort(t.begin(), t.end());
        string ans = s;
        for (int i = 0, j = 0; i < n; ++i) {
            if (s[i] == '?') {
                ans[i] = t[j++];
            }
        }
        return ans;
    }
};

// fill up lower frequencies to [baseline], as evenly as possible
class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        vector<int> freq(27, 0);
        freq[26] = n + 1;
        int m = 0;
        for (char &ch : s) {
            if (ch != '?') {
                freq[ch - 'a']++;
            } else {
                m++;
            }
        }
        auto sf = freq;
        sort(sf.begin(), sf.end());
        int baseline = sf[0];
        int extra = 0;
        for (int i = 1; i < 27; ++i) {
            int vol = i * (sf[i] - sf[i - 1]);
            if (vol >= m) {
                int delta = m / i;
                baseline = sf[i - 1] + delta;
                extra = m % i;
                break;
            }
            m -= vol;
        }
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > baseline) {
                freq[i] = 0;
                continue;
            }
            freq[i] = baseline - freq[i];
            if (extra) {
                freq[i]++;
                extra--;
            }
        }
        string ans = s;
        for (int i = 0, j = 0; i < n; ++i) {
            if (s[i] != '?') {
                continue;
            }
            while (freq[j] == 0) {
                j++;
            }
            ans[i] = 'a' + j;
            freq[j]--;
        }
        return ans;
    }
};