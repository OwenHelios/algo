// https://leetcode.cn/problems/next-greater-node-in-linked-list/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    stack<int> st;
    vector<int> ans;
    void dfs(ListNode* cur, int i) {
        if (!cur) {
            ans.resize(i);
            return;
        }
        dfs(cur->next, i + 1);
        while (!st.empty() && st.top() <= cur->val) {
            st.pop();
        }
        ans[i] = st.empty() ? 0 : st.top();
        st.push(cur->val);
    }

    vector<int> nextLargerNodes(ListNode* head) {
        dfs(head, 0);
        return ans;
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int i = 0;
        stack<int> st;
        vector<int> ans;
        while (head) {
            while (!st.empty() && head->val > ans[st.top()]) {
                ans[st.top()] = head->val;
                st.pop();
            }
            st.push(i++);
            ans.push_back(head->val);
            head = head->next;
        }
        ans[i - 1] = 0;
        while (!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        vector<int> ans;
        for (auto cur = head; cur; cur = cur->next) {
            while (!st.empty() && cur->val > st.top().second) {
                ans[st.top().first] = cur->val;
                st.pop();
            }
            st.emplace(ans.size(), cur->val);
            ans.push_back(0);
        }
        return ans;
    }
};

class Solution {
public:
    ListNode *reverse(ListNode* head) {
        auto cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse(head);
        stack<int> st;
        vector<int> ans;
        for (auto cur = head; cur; cur = cur->next) {
            while (!st.empty() && cur->val >= st.top()) {
                st.pop();
            }
            ans.push_back(st.empty() ? 0 : st.top());
            st.emplace(cur->val);
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};