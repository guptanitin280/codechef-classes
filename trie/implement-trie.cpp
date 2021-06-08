//link:- https://leetcode.com/problems/implement-trie-prefix-tree/

struct node {
    map<char, int> m;
    bool terminate = false;
};
struct Trie{
    node a[100001];
    int ptr=2;

    void insert(string s) {
        int curr = 1;
        for (auto &c:s) {
            if (a[curr].m.count(c)) {
                curr = a[curr].m[c];
            } else {
                a[curr].m[c] = ptr;
                ptr++;
                curr = a[curr].m[c];
            }
        }
        a[curr].terminate=true;
    }
    bool search(string s){
        int curr=1;
        for(auto &c:s) {
            if (!a[curr].m.count(c)) {
                return false;
            }
            curr = a[curr].m[c];
        }
        return a[curr].terminate;
    }
    bool startsWith(string s) {
        int curr = 1;
        for (auto &c:s) {
            if (!a[curr].m.count(c)) {
                return false;
            }
            curr = a[curr].m[c];
        }
        return true;
    }
};