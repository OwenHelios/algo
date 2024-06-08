// https://leetcode.cn/problems/throne-inheritance
#include <bits/stdc++.h>

using namespace std;

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;
    string root;
    ThroneInheritance(string kingName) : root(kingName) {
    }

    void birth(string parentName, string childName) {
        children[parentName].emplace_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        function<void(const string&)> dfs = [&](const string &node) {
            if (dead.find(node) == dead.end()) {
                ans.push_back(node);
            }
            if (children.find(node) == children.end()) return;
            for (auto &c : children[node]) {
                dfs(c);
            }
        };
        dfs(root);
        return ans;
    }
};