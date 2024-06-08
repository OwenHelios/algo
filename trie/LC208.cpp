#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* next[26];
    bool term;
};


class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char ch: word){
            ch -= 'a';
            if (cur->next[ch] == nullptr) {
                cur->next[ch] = new Node();
            }
            cur = cur->next[ch];
        }
        cur->term = true;
    }

    Node* traverse(string s) {
        Node* cur = root;
        for (char ch: s) {
            ch -= 'a';
            if (cur->next[ch] == nullptr) {
                return nullptr;
            }
            cur = cur->next[ch];
        }
        return cur;
    }
    
    bool search(string word) {
        Node* node = traverse(word);
        return node != nullptr && node->term;
    }
    
    bool startsWith(string prefix) {
        Node* node = traverse(prefix);
        return node != nullptr;
    }
};
