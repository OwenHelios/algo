#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct Node {
        Node* next[26];
        int score = 0;
        vector<int> ids;
    };
    
    vector<int> ans;
    void dfs(Node* node, int sum){
        if(node==nullptr) return;
        sum += node->score;
        for (int id: node->ids){
            ans[id] = sum;
        }
        for (Node* child: node->next) {
            dfs(child, sum);
        }
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();
        int n = words.size();
        for(int i=0;i<n;++i){
            Node* cur = root;
            for(char ch: words[i]) {
                if (cur->next[ch-'a'] == nullptr) {
                    cur->next[ch-'a'] = new Node();
                }
                cur = cur->next[ch-'a'];
                cur->score++;
            }
            cur->ids.push_back(i);
        }
        ans.resize(n);
        dfs(root, 0);
        return ans;
    }
};