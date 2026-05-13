class Solution {
public:
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]); // Path compression
        }
        void unite(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) parent[rootI] = rootJ;
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;
        int id = 0;

        // 1. Map mỗi email duy nhất với một ID số nguyên
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                if (emailToId.find(acc[i]) == emailToId.end()) {
                    emailToId[acc[i]] = id++;
                    emailToName[acc[i]] = name;
                }
            }
        }

        // 2. Thực hiện Union các email trong cùng một account
        DSU dsu(id);
        for (auto& acc : accounts) {
            int firstEmailId = emailToId[acc[1]];
            for (int i = 2; i < acc.size(); i++) {
                dsu.unite(firstEmailId, emailToId[acc[i]]);
            }
        }

        // 3. Gom nhóm email theo root ID
        unordered_map<int, vector<string>> groups;
        for (auto const& [email, eId] : emailToId) {
            int root = dsu.find(eId);
            groups[root].push_back(email);
        }

        // 4. Định dạng kết quả đầu ra
        vector<vector<string>> res;
        for (auto& [rootId, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(emailToName[emails[0]]); // Lấy name từ email đầu tiên
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }

        return res;
    }
};
