
struct TrieNode 
{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }   
};

struct Trie
{
    TrieNode* root;
    vector<string> result;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr = root;
        vector<string> result;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }
    void startsWith(string prefix) {
        TrieNode* curr = root;
        result.clear();
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return;
            }
            curr = curr->children[index];
        }
        dfs(curr, prefix);
    }

    void dfs(TrieNode* node, string word) {
        if (result.size() == 3) {
            return;
        }
        if (node->isEndOfWord) {
            result.push_back(word);
        }
        for (int i = 0; i < 26; i++) 
        {
            if (node->children[i] != nullptr) {
                dfs(node->children[i], word + char(i + 'a'));
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        Trie* trie = new Trie();
        for (string i: products)
        {
            trie->insert(i);
        }
        string temp = "";
        for (char i: searchWord)
        {
            temp.push_back(i);
            trie->startsWith(temp);
            result.push_back(trie->result);
        }
        return result;
    }
};
