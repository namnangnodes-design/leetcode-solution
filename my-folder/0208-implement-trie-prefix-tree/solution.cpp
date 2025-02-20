struct Trienode
{
    Trienode* child[26];
    bool isWord;
    Trienode()
    {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trienode* root;
    Trie() {
        root = new Trienode();
    }

    void insert(string word) {
        Trienode* p = root;
        for (char c : word) {
            if (!p->child[c - 'a']) {  // Create node only if it doesn't exist
                p->child[c - 'a'] = new Trienode();
            }
            p = p->child[c - 'a'];
        }
        p->isWord = true;
    }

    bool search(string word) {
        Trienode* p = root;
        for (char c : word) {
            if (!p->child[c - 'a']) {
                return false;
            }
            p = p->child[c - 'a'];
        }
        return p->isWord;
    }

    bool startsWith(string prefix) {
        Trienode* p = root;
        for (char c : prefix) {
            if (!p->child[c - 'a']) {
                return false;
            }
            p = p->child[c - 'a'];
        }
        return true;
    }
};

